#include "snake.h"

Snake::Snake(QWidget *parent) : QWidget(parent)
{
    this->resize(450,300);
//    this->setWindowIcon(QIcon(":/images/rom_back.png"));
    this->setWindowTitle("Calendar");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/management_back.png").scaled(this->size())));
    this->setPalette(palette);

    snake = new QPushButton(this);
    snake->setIcon(QIcon(":/images/snake_back.png"));
    snake->setIconSize(QSize(400,200));
    snake->setGeometry(QRect(40,40,400,200));
    snake->setFlat(true);
//    App_map->hide();
}
