 #include "map_app.h"

map_app::map_app(QWidget *parent) : QWidget(parent)
{
    this->resize(1000,643);
//    this->setWindowIcon(QIcon(":/images/rom_back.png"));
    this->setWindowTitle("Map");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/map1.jpg").scaled(this->size())));
    this->setPalette(palette);
}
