#include "wallpaper.h"
#include "ui_wallpaper.h"

WallPaper::WallPaper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WallPaper)
{
    ui->setupUi(this);
    this->resize(700,454);
    this->setWindowTitle("Wall Paper");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/background wallpaper.jpg").scaled(this->size())));
    this->setPalette(palette);

    ui->pushButton->setIcon(QIcon(":/images/background.jpg"));
    ui->pushButton->setIconSize(QSize(300,200));
    ui->pushButton->setGeometry(QRect(20,50,300,200));
    ui->pushButton->setFlat(true);

    ui->pushButton_2->setIcon(QIcon(":/images/background.png"));
    ui->pushButton_2->setIconSize(QSize(300,200));
    ui->pushButton_2->setGeometry(QRect(375,50,300,200));
    ui->pushButton_2->setFlat(true);
}

WallPaper::~WallPaper()
{
    delete ui;
}

void WallPaper::on_pushButton_clicked()
{
    emit choose_wallpaper(0);
    this -> close();
}

void WallPaper::on_pushButton_2_clicked()
{
    emit choose_wallpaper(1);
    this -> close();
}

//void WallPaper::on_pushButton_3_clicked(){
//    emit choose_wallpaper(2);
//    this -> close();
//}

//void WallPaper::on_pushButton_4_clicked(){
//    emit choose_wallpaper(3);
//    this -> close();
//}
