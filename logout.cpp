#include "logout.h"
#include "ui_logout.h"

LogOut::LogOut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogOut)
{
    ui->setupUi(this);
}

LogOut::~LogOut()
{
    delete ui;
}

void LogOut::on_buttonBox_accepted()
{
    this -> close();
    emit close_main();
}
