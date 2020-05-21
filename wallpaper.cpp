#include "wallpaper.h"
#include "ui_wallpaper.h"

WallPaper::WallPaper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WallPaper)
{
    ui->setupUi(this);
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
