#include "filemanager.h"
#include "ui_filemanager.h"
#include<QDebug>
#include <QMessageBox>
//#include <QTextEdit>

FileManager::FileManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileManager)
{
    ui->setupUi(this);
    connect(this,SIGNAL(Init()),this,SLOT(Root()));
    connect(ui->lwt_File,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(ItemDoubleClicked(QListWidgetItem*)));
    connect(ui->btn_Root,SIGNAL(clicked()),this,SLOT(Root()));
    connect(ui->btn_Save,SIGNAL(clicked()),this,SLOT(Save()));
    connect(ui->btn_Copy,SIGNAL(clicked()),this,SLOT(Copy()));
    connect(ui->btn_New,SIGNAL(clicked()),this,SLOT(New()));
    connect(ui->btn_Rename,SIGNAL(clicked()),this,SLOT(Rename()));
    connect(ui->btn_Paste,SIGNAL(clicked()),this,SLOT(Paste()));
    connect(ui->btn_Delete,SIGNAL(clicked()),this,SLOT(Delete()));
    connect(ui->btn_Enter,SIGNAL(clicked()),this,SLOT(Enter()));
    connect(ui->btn_Up,SIGNAL(clicked()),this,SLOT(Up()));
    connect(ui->btn_Exit,SIGNAL(clicked()),this,SLOT(Exit()));
    copyFile=NULL;
    rootDir.setPath(rootPath);
    CurrentContent = new QTextEdit(this);
    CurrentContent -> setGeometry(20, 60, 421, 351);
    CurrentContent -> document() -> setModified(false);
    CurrentContent -> hide();

    rootPath = "/Users/wulan/Desktop";
    //UIdesign/TextFile

    emit Init();
}
FileManager::~FileManager()
{
    delete ui;
}
void FileManager::ShowFile(QDir dir)
{
    ui->lwt_File->clear();
    QFileInfoList fileList=dir.entryInfoList();
    for (int i=2;i<dir.count();i++)
    {
        QIcon icon;
        QListWidgetItem *item=new QListWidgetItem (fileList.at(i).fileName());
        if (fileList.at(i).isDir())
            icon.addFile(QString::fromUtf8(":/Pic/Menu"), QSize(), QIcon::Normal, QIcon::Off);
        else icon.addFile(QString::fromUtf8(":/Pic/File"), QSize(), QIcon::Normal, QIcon::Off);
        item->setIcon(icon);
        ui->lwt_File->addItem(item);
    }
}
void FileManager::ChangePath(QString path)
{
    dir.setPath(path);
    dirPath=dir.absolutePath();
//    relativePath = dir.relativeFilePath(rootPath);
    relativePath = rootDir.relativeFilePath(dirPath);
//    ui->let_Menu->setText(dir.absolutePath());

    if (dirPath != rootPath)
    {
        ui->let_Menu->setText("." + relativePath);
        return;
    }
    ui->let_Menu->setText(relativePath);
}
void FileManager::Go()
{
    QFileInfo file;
    if (ui->let_Menu->text()==relativePath)
    {
        if (ui->lwt_File->selectedItems().count()>0)
            file.setFile(dir,ui->lwt_File->selectedItems().first()->text());
        else file.setFile(dir.dirName());
    }
    else {
        file.setFile(ui->let_Menu->text());
        if (!file.isDir())
            if (ui->lwt_File->selectedItems().count()>0)
                file.setFile(dir,ui->lwt_File->selectedItems().first()->text());
            else file.setFile(dir.dirName());
    }
    if (file.isDir())
    {
        ChangePath(file.filePath());
        ShowFile(dir);
    }
    else if (file.suffix() == "txt")
    {
//        QString name = file.fileName();//返回文件名称
        QString path = file.filePath();//返回文件路径，包含文件名
//        QString path1 = file.path();//返回文件路径，不包含文件名
        ChangePath(path);
        QFile file(path);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream textStream(&file);
//        QTextEdit *CurrentContent;
//        CurrentContent = new QTextEdit(this);
//        CurrentContent -> setGeometry(20, 60, 421, 351);
        CurrentContent->setText(textStream.readAll());
        CurrentContent -> show();
        file.close();
    }
    else {
        ChangePath(file.path());
        ShowFile(dir);
        QProcess *pro=new QProcess();
        pro->start(file.filePath());
        }
}
void FileManager::PasteFile(QString oldFileName, QString newFileName)
{
    QFileInfo file(oldFileName);
    if (file.isDir())
    {
        QDir oldMenu,newMenu;
        oldMenu.setPath(oldFileName);
        newMenu.mkdir(newFileName);
        QFileInfoList fileList=oldMenu.entryInfoList();
        for (int i=2;i<fileList.count();i++)
            PasteFile(oldFileName+"/"+fileList.at(i).fileName(),newFileName+"/"+fileList.at(i).fileName());
    }
    else
        QFile::copy(oldFileName,newFileName);
}
void FileManager::DeleteFile(QString fileName)
{
   QFileInfo file(fileName);
   if (file.isDir())
   {
       QDir fileDir;
       fileDir.setPath(fileName);
       QFileInfoList fileList=fileDir.entryInfoList();
       for (int i=2;i<fileList.count();i++)
           DeleteFile(fileName+"/"+fileList.at(i).fileName());
       fileDir.rmdir(fileName);
   }
   else
       QFile::remove(fileName);
}

void FileManager::SaveFile()
{
    QFile file(dirPath);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream textStream(&file);
    file.resize(0);
    textStream << CurrentContent -> toPlainText();
    file.close();
    CurrentContent->document()->setModified(false);
    return;
}


void FileManager::Root()
{
    if (dirPath.length()>3 && dirPath.endsWith("txt"))
    {
        CurrentContent->clear();
        CurrentContent->hide();
    }
    ChangePath(rootPath);
    ShowFile(dir);
}

void FileManager::Copy()
{
    if (dirPath.length()>3 && dirPath.endsWith("txt"))
    {
        return;
    }
    GetCopyFile();
}

void FileManager::New()
{
    if (! (dirPath.length()>3 && dirPath.endsWith("txt")))
    {

    }
    return;
}

void FileManager::Rename()
{
    return;
}

void FileManager::Save()
{
    if (dirPath.length()>3 && dirPath.endsWith("txt"))
    {
        SaveFile();
    }
}

void FileManager::Paste()
{
    if (dirPath.length()>3 && dirPath.endsWith("txt"))
    {
        return;
    }
    if (copyFile->filePath=="/")
        copyFile->filePath="";
    if (dirPath=="/")
        dirPath="";
    PasteFile(copyFile->filePath+"/"+copyFile->fileName,dirPath+"/"+copyFile->fileName);
    if (copyFile->filePath=="")
        copyFile->filePath="/";
    if (dirPath=="")
        dirPath="/";
    dir.setPath(dirPath);
    ShowFile(dir);
}

void FileManager::Delete()
{
    if (dirPath.length()>3 && dirPath.endsWith("txt"))
    {
        return;
    }
    if (ui->lwt_File->selectedItems().count()<=0)
        return;
    if (dirPath=="/")
        dirPath="";
    DeleteFile(dirPath+"/"+ui->lwt_File->selectedItems().first()->text());

    if (dirPath=="")
        dirPath="/";
    dir.setPath(dirPath);
    ShowFile(dir);
}
void FileManager::Enter()
{
    if (dirPath.length()>3 && dirPath.endsWith("txt"))
    {
        return;
    }
    Go();
}
void FileManager::Up()
{
    if (dirPath.length()>3 && dirPath.endsWith("txt"))
    {
        if (CurrentContent->document()->isModified())
        {
            int test = QMessageBox::warning(this,tr("警告"),tr("还未保存"),QMessageBox::Save|QMessageBox::Ignore|QMessageBox::Cancel);
            if (test == QMessageBox::Save)
            {
                SaveFile();
                return;
            } else if (test == QMessageBox::Cancel)
            {
                return;
            }
        }
        CurrentContent->clear();
        CurrentContent->hide();
    }
    if (dirPath == rootPath)
    {
        return;
    }
    dir.cd("..");
    ChangePath(dir.path());
    ShowFile(dir);
}
void FileManager::Exit()
{
    exit(0);
}
void FileManager::ItemDoubleClicked(QListWidgetItem*)
{
    Go();
}
void FileManager::GetCopyFile()
{
    if (ui->lwt_File->selectedItems().count()<=0)
        return;
//    copyFlag=function;
    copyFile=new CopyFile(dirPath,ui->lwt_File->selectedItems().first()->text());
}

