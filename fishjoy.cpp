#include "fishjoy.h"

Fishjoy::Fishjoy(QWidget *parent) : QWidget(parent)
{
    this->resize(450,550);
//    this->setWindowIcon(QIcon(":/images/rom_back.png"));
    this->setWindowTitle("Calendar");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/management_back.png").scaled(this->size())));
    this->setPalette(palette);

    fish = new QPushButton(this);
    fish->setIcon(QIcon(":/images/map_back.png"));
    fish->setIconSize(QSize(247,450));
    fish->setGeometry(QRect(70,40,247,450));
    fish->setFlat(true);
//    App_map->hide();
}
