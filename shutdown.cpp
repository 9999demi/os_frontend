#include "shutdown.h"
#include "ui_shutdown.h"

ShutDown::ShutDown(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShutDown)
{
    ui->setupUi(this);
}

ShutDown::~ShutDown()
{
    delete ui;
}

void ShutDown::on_buttonBox_accepted()
{
    this -> close();
    emit shut_main();
}
