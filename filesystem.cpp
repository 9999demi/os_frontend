#include "filesystem.h"
#include "ui_filesystem.h"

FileSystem::FileSystem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileSystem)
{
    ui->setupUi(this);
    this->resize(1000, 708);
}

FileSystem::~FileSystem()
{
    delete ui;
}
