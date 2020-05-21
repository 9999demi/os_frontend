#include "start.h"
#include "ui_start.h"
#include "widget.h"

Start::Start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_clicked()
{
    this -> close();
    Widget *w = new Widget;
    w -> show();
}
