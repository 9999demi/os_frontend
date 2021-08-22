#include "chess.h"

Chess::Chess(QWidget *parent) : QWidget(parent)
{
    this->resize(450,300);
//    this->setWindowIcon(QIcon(":/images/rom_back.png"));
    this->setWindowTitle("Calendar");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/management_back.png").scaled(this->size())));
    this->setPalette(palette);

    chess = new QPushButton(this);
    chess->setIcon(QIcon(":/images/snake_back.png"));
    chess->setIconSize(QSize(400,200));
    chess->setGeometry(QRect(40,40,400,200));
    chess->setFlat(true);
}
