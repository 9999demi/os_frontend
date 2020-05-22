#include "mainwindow.h"
#include <QMenuBar>                   //菜单栏
#include <QMenu>                      //菜单
#include <QAction>                    //菜单项
#include <QDebug>                     //输出
#include <QToolBar>                   //工具栏
#include <QPushButton>                //按钮
#include <QStatusBar>                 //状态栏
#include <QLabel>                     //标签
#include <QTextEdit>                  //文本编辑区
#include <QDockWidget>                //浮动窗口
#include <QDialog>                    //对话框
#include <QMessageBox>                //标准对话框
#include <QFileDialog>                //文件对话框

#include "logout.h"
#include "widget.h"
#include "shutdown.h"
#include "start.h"
#include "wallpaper.h"
#include "ram.h"
#include "rom.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1000, 708);
    this->setWindowTitle("Main Window");
    this->setStyleSheet("MainWindow{border-image: url(:/images/background.jpg);}");
//    QPalette palette;
//    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/background.png").scaled(this->size())));
//    this->setPalette(palette);

//    QPalette palette;
//    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/background.jpg").scaled(this->size())));
    //菜单栏
      QMenuBar *mBar = menuBar();
    //菜单-文件
      QMenu *pMenuBarAbout= new QMenu(QStringLiteral("About(&A)"));
      QAction *aActionAccounts = new QAction(QStringLiteral("Accounts"), this);
//     pActionOpen->setIcon(QIcon(":/ReplicationTool/png/open.png"));
      aActionAccounts->setShortcut(Qt::CTRL | Qt::Key_A);
      pMenuBarAbout->addAction(aActionAccounts);
//      QAction *aActionCapacity = new QAction(QStringLiteral("Capacity"), this);
//      aActionCapacity->setShortcut(Qt::CTRL | Qt::Key_C);
//      pMenuBarAbout->addAction(aActionCapacity);
      pMenuBarAbout->addSeparator();
      QAction *aActionCapacity = pMenuBarAbout->addAction("Capacity");
      aActionCapacity->setShortcut(Qt::CTRL | Qt::Key_C);
      connect(aActionCapacity,&QAction::triggered,
              [=]()
      {
           QMessageBox::about(this,"Capacity","ROM & RAM");     //about(父类,标题名，对话框内容）;
      }
              );
//      QAction *aActionStorage = new QAction(QStringLiteral("Storage"), this);
//      aActionStorage->setShortcut(Qt::CTRL | Qt::Key_S);
//      pMenuBarAbout->addAction(aActionStorage);
      QAction *aActionStorage = pMenuBarAbout->addAction("Storage");
      aActionStorage->setShortcut(Qt::CTRL | Qt::Key_S);
      connect(aActionStorage,&QAction::triggered,
              [=]()
      {
           QMessageBox::about(this,"Storage","Image & Text");
      }
              );
      pMenuBarAbout->addSeparator();
//      QAction *aActionWallpaper = new QAction(QStringLiteral("Wallpaper"), this);
//      aActionWallpaper->setShortcut(Qt::CTRL | Qt::Key_W);
//      pMenuBarAbout->addAction(aActionWallpaper);
      QAction *aActionWallpaper = pMenuBarAbout->addAction("Wallpaper");
      connect(aActionWallpaper,&QAction::triggered,
              [=]()
      {
//          QString path = QFileDialog::getOpenFileName(
//                      this,
//                      "open",
//                      "../",
//                      "souce(*.cpp *.h);;"
//                      "Text(*.txt);;"
//                      "all(*.*)" );

//          qDebug() << path;


          // Function: change the wallpaper.
          WallPaper w;
          connect(&w, SIGNAL(choose_wallpaper(int)), this, SLOT(change_wallpaper(int)));
          w.exec();
      }
              );

      QMenu *pMenuBarLogOut= new QMenu(QStringLiteral("Log Out(&L)"));

      QAction *logout = pMenuBarLogOut->addAction("Log out your account");
      connect(logout,&QAction::triggered,
              [=]()
      {
//           QMessageBox::question(this,"question","Are you sure to log out your account?",
//                                 QMessageBox::Ok,QMessageBox::Cancel);     //question(父类,标题名，对话框内容）;
          LogOut l;
          connect(&l, SIGNAL(close_main()), this, SLOT(menu_logout()));
          l.exec();
      }
              );

//      connect(logout, SIGNAL(triggered()), this, SLOT(menu_logout()) );


      QMenu *pMenuBarShutDown= new QMenu(QStringLiteral("Shut Down(&S)"));
      QAction *shutdown = pMenuBarShutDown->addAction("Shut down the system");
//      connect(shutdown,SIGNAL(clicked()),this,SLOT(exitb()));
      connect(shutdown,&QAction::triggered,
              [=]()
      {
//           QMessageBox::question(this,"question","Are you really sure to exit?",
//                                 QMessageBox::Yes,QMessageBox::Close);     //question(父类,标题名，对话框内容）;
//           exit(0);
          ShutDown s;
          connect(&s, SIGNAL(shut_main()), this, SLOT(menu_shutdown()));
          s.exec();
      }
              );

//      connect(shutdown, SIGNAL(triggered()), this, SLOT(menu_shutdown()) );


      mBar->addMenu(pMenuBarAbout);
      mBar->addMenu(pMenuBarLogOut);
      mBar->addMenu(pMenuBarShutDown);


//         //模态对话框
//           QAction *p1 = pFile->addAction("模态对话框");
//           connect(p1,&QAction::triggered,
//                   [=]()
//           {
//                QDialog dlg;
//                dlg.exec();
//                qDebug() << "模态对话框打开时，无法操作其他";
//           }

//                   );


//           //非模态对话框
//           pFile->addSeparator(); //添加分割线

//           QAction *p2 = pFile->addAction("非模态对话框");
//           connect(p2,&QAction::triggered,
//                   [=]()
//           {
//               QDialog *dlg = new QDialog(this);
//               dlg->setAttribute(Qt::WA_DeleteOnClose);     //防止内存泄漏，此函数的作用为关闭对话框时自动释放
//               dlg->show();
//               qDebug() << "非模态对话框打开时，可以操作其他";
//           }

//                   );


//           //关于对话框
//           pMenuBarAbout->addSeparator(); //添加分割线

//           QAction *p3 = pMenuBarAbout->addAction("关于对话框");
//           connect(p3,&QAction::triggered,
//                   [=]()
//           {
//                QMessageBox::about(this,"about","ROM:");     //about(父类,标题名，对话框内容）;
//           }

//                   );


//           //问题对话框
//           pMenuBarAbout->addSeparator(); //添加分割线

//           QAction *p4 = pMenuBarAbout->addAction("问题对话框");
//           connect(p4,&QAction::triggered,
//                   [=]()
//           {
//                QMessageBox::question(this,"question","Are you sure to exit?",QMessageBox::Ok,QMessageBox::Cancel);     //question(父类,标题名，对话框内容）;
//           }

//                   );

//           //文件对话框
//           pMenuBarAbout->addSeparator(); //添加分割线

//           QAction *p5 = pMenuBarAbout->addAction("文件对话框");
//           connect(p5,&QAction::triggered,
//                   [=]()
//           {
//               QString path = QFileDialog::getOpenFileName(
//                           this,
//                           "open",
//                           "../",
//                           "souce(*.cpp *.h);;"
//                           "Text(*.txt);;"
//                           "all(*.*)" );

//               qDebug() << path;
//           }
//                   );


    //工具栏  菜单项的快捷方式
           QToolBar *toolBar = addToolBar("toolBar");
           //工具栏添加快捷键

           toolBar->addAction(aActionAccounts);
           toolBar->addSeparator();
           toolBar->addAction(aActionCapacity);
           toolBar->addSeparator();
           toolBar->addAction(aActionWallpaper);
            //添加小控件ce
           QPushButton *b = new QPushButton(this);
           b->setText("Calender");
           toolBar->addWidget(b);
           connect(b,&QPushButton::clicked,this,&MainWindow::MySlot);

    //状态栏
//           QStatusBar *sBar = statusBar();
//           QLabel *MyLabel = new QLabel(this);
//           MyLabel->setText("第一种添加方式 ");
//           sBar->addWidget(MyLabel);
//           // addwidget从左往右添加
//           sBar->addWidget(new QLabel("addwidget从左往右添加",this));
//           sBar->addPermanentWidget(new QLabel("addPermanentWidget从右往左添加",this));

           QStatusBar *pStatusBar = statusBar();

           QLabel *pWelCome = new QLabel(QStringLiteral("   Come on let's fall in love......"));
           pStatusBar->addWidget(pWelCome);

           QProgressBar * pProgressBar = new QProgressBar();
           pProgressBar->setRange(0,100);
           pProgressBar->setValue(20);
           pProgressBar->setMaximumWidth(200);
           pStatusBar->addPermanentWidget(pProgressBar);
           pTimeLabel = new QLabel();
           pStatusBar->addPermanentWidget(pTimeLabel);

           QTimer *pTimer = new QTimer(this);
           pTimer->start(1000);
           connect(pTimer, SIGNAL(timeout()),this,SLOT(updata_time()));

//           //更新时间的槽函数中的代码
//           QDateTime currentTime = QDateTime::currentDateTime();
//           QString timeStr = currentTime.toString(QStringLiteral("yyyy年MM月dd日 hh:mm:ss"));

//           pTimeLabel->setText(timeStr);

    //文本编辑区
//           QTextEdit *MyQTE = new QTextEdit(this);
//           setCentralWidget(MyQTE);
    //浮动窗口
//           QDockWidget *dock = new QDockWidget(this);
//           addDockWidget(Qt::RightDockWidgetArea,dock);
//           //给浮动窗口添加文本编辑区
//           QTextEdit *MyDockQTE = new QTextEdit(this);
//           dock->setWidget(MyDockQTE);

           App1 = new QPushButton(this);
           App1->setIcon(QIcon(":/images/Gluttonous Snake.jpg"));
           App1->setIconSize(QSize(100,100));
           App1->setGeometry(QRect(850,80,100,100));
           App1->setFlat(true);


// From Moniter package
           ROM_btn = new QPushButton(this);
           ROM_btn->setIcon(QIcon(":/images/rom.png"));
           ROM_btn->setIconSize(QSize(65,29));
           ROM_btn->setGeometry(QRect(0,0,65,29));
           ROM_btn->setFlat(true);

           RAM_btn = new QPushButton(this);
           RAM_btn->setIcon(QIcon(":/images/ram.png"));
           RAM_btn->setIconSize(QSize(65,29));
           RAM_btn->setGeometry(QRect(70,0,65,29));
           RAM_btn->setFlat(true);

           store = new QPushButton(this);
           store->setIcon(QIcon(":/images/Appstore.png"));
           store->setIconSize(QSize(45,45));
           store->setGeometry(QRect(25,50,45,45));
           store->setFlat(true);

           calendar = new QPushButton(this);
           calendar->setIcon(QIcon(":/images/calendar.png"));
           calendar->setIconSize(QSize(45,45));
           calendar->setGeometry(QRect(25,110,45,45));
           calendar->setFlat(true);

           snake = new QPushButton(this);
           snake->setIcon(QIcon(":/images/Snake.png"));
           snake->setIconSize(QSize(50,50));
           snake->setGeometry(QRect(23,170,50,50));
           snake->setFlat(true);

           map = new QPushButton(this);
           map->setIcon(QIcon(":/images/map.png"));
           map->setIconSize(QSize(50,50));
           map->setGeometry(QRect(23,230,50,50));
           map->setFlat(true);
           map->hide();

           chess = new QPushButton(this);
           chess->setIcon(QIcon(":/images/chess.png"));
           chess->setIconSize(QSize(44,44));
           chess->setGeometry(QRect(23,290,44,44));
           chess->setFlat(true);
           chess->hide();

           fish = new QPushButton(this);
           fish->setIcon(QIcon(":/images/fishjoy.png"));
           fish->setIconSize(QSize(46,46));
           fish->setGeometry(QRect(23,350,46,46));
           fish->setFlat(true);
           fish->hide();

           cal_place = 0;
           snake_place = 1;
           map_place = -1;
           chess_place = -1;
           fish_place = -1;

           mem_arr = new int[5];
           mem_arr[0] = 1;
           mem_arr[1] = 1;
           mem_arr[2] = 0;
           mem_arr[3] = 0;
           mem_arr[4] = 0;

           ram = new RAM();
           rom = new ROM();

           appstore = new Appstore();
           this->connect(ROM_btn,SIGNAL(clicked()),this,SLOT(ROM_click()));
           this->connect(RAM_btn,SIGNAL(clicked()),this,SLOT(RAM_click()));
           this->connect(store,SIGNAL(clicked()),this,SLOT(store_click()));
           //download
           this->connect(appstore->map_status,SIGNAL(clicked()),this,SLOT(map_download()));
           this->connect(appstore->chess_status,SIGNAL(clicked()),this,SLOT(chess_download()));
           this->connect(appstore->fish_status,SIGNAL(clicked()),this,SLOT(fish_download()));
           this->connect(appstore->calendar_status,SIGNAL(clicked()),this,SLOT(cal_download()));
           this->connect(appstore->snake_status,SIGNAL(clicked()),this,SLOT(snake_download()));
           //Uninstall
           this->connect(appstore->map_uninstall,SIGNAL(clicked()),this,SLOT(map_uninstall()));
           this->connect(appstore->cal_uninstall,SIGNAL(clicked()),this,SLOT(cal_uninstall()));
           this->connect(appstore->snake_uninstall,SIGNAL(clicked()),this,SLOT(snake_uninstall()));
           this->connect(appstore->chess_uninstall,SIGNAL(clicked()),this,SLOT(chess_uninstall()));
           this->connect(appstore->fish_uninstall,SIGNAL(clicked()),this,SLOT(fish_uninstall()));
           //ROM
           this->connect(appstore->fish_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));
           this->connect(appstore->calendar_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));
           this->connect(appstore->map_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));
           this->connect(appstore->snake_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));
           this->connect(appstore->chess_status,SIGNAL(clicked()),this,SLOT(app_rom_change()));

           this->connect(appstore->cal_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));
           this->connect(appstore->map_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));
           this->connect(appstore->fish_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));
           this->connect(appstore->chess_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));
           this->connect(appstore->snake_uninstall,SIGNAL(clicked()),this,SLOT(app_rom_change()));

           //Details
           this->connect(rom->Manage,SIGNAL(clicked()),this,SLOT(set_app_details()));

}

void MainWindow::MySlot(){
    qDebug() << "succeed!";
}

void MainWindow::updata_time()
{
    QDateTime cur_time = QDateTime::currentDateTime();
    QString timestr = cur_time.toString("MM/dd/yyyy hh:mm:ss");
    pTimeLabel -> setText(timestr);
}

void MainWindow::exitb(){
    if (QMessageBox::Yes == QMessageBox::question(this,"Reminder","Are you really sure to exit?",QMessageBox::Yes,QMessageBox::Close)){
        delete this;
        exit(0);
    }
}

void MainWindow::menu_logout()
{
//    LogOut l;
//    l.exec();
    this -> close();
    Widget *w = new Widget;
    w -> show();
//    qDebug() << "yes" << endl;
//    qDebug() << "ye" << endl;
}


void MainWindow::menu_shutdown()
{
    this -> close();
    Start *s = new Start;
    s -> show();
}

void MainWindow::change_wallpaper(int i)
{
    if (i == 0)
    {
        this->setStyleSheet("MainWindow{border-image: url(:/images/background.jpg);}");
    }
    if (i == 1)
    {
        this->setStyleSheet("MainWindow{border-image: url(:/images/background.png);}");
    }
}

MainWindow::~MainWindow()
{
    delete ROM_btn;
    delete RAM_btn;
}



// From Moniter Package

void MainWindow::RAM_click(){
//    ram = new RAM();
//    ram->setAttribute(Qt::WA_DeleteOnClose);
    ram->show();
}

void MainWindow::ROM_click(){
//    rom = new ROM();
//    rom->setAttribute(Qt::WA_DeleteOnClose);
    rom->show();
}

void MainWindow::store_click(){
//    appstore->setAttribute(Qt::WA_DeleteOnClose);
    appstore->show();
}

void MainWindow::map_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        map->setGeometry(QRect(23,110,50,50));
        map->show();
    }else if(place == 1){
        map->setGeometry(QRect(23,170,50,50));
        map->show();
    }else if(place == 2){
        map->setGeometry(QRect(23,230,50,50));
        map->show();
    }else if(place == 3){
        map->setGeometry(QRect(23,290,50,50));
        map->show();
    }else if(place == 4){
        map->setGeometry(QRect(23,350,50,50));
        map->show();
    }
    map_place = place;
}

void MainWindow::chess_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        chess->setGeometry(QRect(23,110,44,44));
        chess->show();
    }else if(place == 1){
        chess->setGeometry(QRect(23,170,44,44));
        chess->show();
    }else if(place == 2){
        chess->setGeometry(QRect(23,230,44,44));
        chess->show();
    }else if(place == 3){
        chess->setGeometry(QRect(23,290,44,44));
        chess->show();
    }else if(place == 4){
        chess->setGeometry(QRect(23,350,44,44));
        chess->show();
    }
    chess_place = place;
}

void MainWindow::fish_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        fish->setGeometry(QRect(23,110,46,46));
        fish->show();
    }else if(place == 1){
        fish->setGeometry(QRect(23,170,46,46));
        fish->show();
    }else if(place == 2){
        fish->setGeometry(QRect(23,230,46,46));
        fish->show();
    }else if(place == 3){
        fish->setGeometry(QRect(23,290,46,46));
        fish->show();
    }else if(place == 4){
        fish->setGeometry(QRect(23,350,46,46));
        fish->show();
    }
    fish_place = place;
}

void MainWindow::cal_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        calendar->setGeometry(QRect(23,110,45,45));
        calendar->show();
    }else if(place == 1){
        calendar->setGeometry(QRect(23,170,45,45));
        calendar->show();
    }else if(place == 2){
        calendar->setGeometry(QRect(23,230,45,45));
        calendar->show();
    }else if(place == 3){
        calendar->setGeometry(QRect(23,290,45,45));
        calendar->show();
    }else if(place == 4){
        calendar->setGeometry(QRect(23,350,45,45));
        calendar->show();
    }
    cal_place = place;
}

void MainWindow::snake_download(){
    int place = 10;
    for (int i=0;i<5;i++){
        if (mem_arr[i] == 0){
            place = i;
            mem_arr[i] = 1;
            break;
        }
    }
    if(place == 0){
        snake->setGeometry(QRect(23,110,50,50));
        snake->show();
    }else if(place == 1){
        snake->setGeometry(QRect(23,170,50,50));
        snake->show();
    }else if(place == 2){
        snake->setGeometry(QRect(23,230,50,50));
        snake->show();
    }else if(place == 3){
        snake->setGeometry(QRect(23,290,50,50));
        snake->show();
    }else if(place == 4){
        snake->setGeometry(QRect(23,350,50,50));
        snake->show();
    }
    snake_place = place;
}

void MainWindow::map_uninstall(){
    map->hide();
    mem_arr[map_place] = 0;
}

void MainWindow::cal_uninstall(){
    calendar->hide();
    mem_arr[cal_place] = 0;
}

void MainWindow::snake_uninstall(){
    snake->hide();
    mem_arr[snake_place] = 0;
}

void MainWindow::chess_uninstall(){
    chess->hide();
    mem_arr[chess_place] = 0;
}
void MainWindow::fish_uninstall(){
    fish->hide();
    mem_arr[fish_place] = 0;
}

int MainWindow::progress_len(){
    //the number of 1 in app_status_arr
    int num = 0;
    for (int i = 0; i<5; i++){
        if (appstore->app_status_arr[i] == 1){
            num++;
        }
    }
    return num;
}

void MainWindow::app_rom_change(){
    int num = progress_len();
    if (num == 0){
        rom->blue2->hide();
    }else if (num == 1){
        rom->blue2->setGeometry(QRect(138,71,82,18));
    }else if (num == 2){
        rom->blue2->setGeometry(QRect(146,71,82,18));
    }else if (num ==3){
        rom->blue2->setGeometry(QRect(154,71,82,18));
    }else if (num ==4){
        rom->blue2->setGeometry(QRect(162,71,82,18));
    }else{
        rom->blue2->setGeometry(QRect(170,71,82,18));
    }
    rom->app_memory = app_ROM();
    rom->App->setToolTip(QString("%1GB").arg(rom->app_memory));
    rom->Available->setToolTip(QString("%1GB").arg(6.0 - 0.87 - rom->app_memory));
}

void MainWindow::set_app_details(){
    for (int i=0; i<5; i++){
        rom->app_mem_arr[i] = appstore->app_status_arr[i];
    }
}

double MainWindow::app_ROM(){
    double base = 1.62;
    for(int i=0; i<5;i++){
        if (appstore->app_status_arr[i] == 1){
            base = base + rom->mem_rom_arr[i];
        }
    }
    return base;
}

