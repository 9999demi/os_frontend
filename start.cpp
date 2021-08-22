#include "start.h"
//#include "ui_start.h"
#include "widget.h"

Start::Start(QWidget *parent) :
    QDialog(parent)
//    ui(new Ui::Start)
{
    this->resize(1000, 708);
    this->setWindowTitle("Stanby Mode");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/images/background login.jpeg").scaled(this->size())));
    this->setPalette(palette);
//    ui->setupUi(this);

    startbutton = new QPushButton(this);
    startbutton->setIcon(QIcon(":/images/start_btn.png"));
    startbutton->setIconSize(QSize(100,100));
    startbutton->setGeometry(QRect(460,450,100,100));
    startbutton->setFlat(true);

    tips1 = new QLabel(this);
    QFont ft;
    ft.setPointSize(19);
    tips1->setGeometry(300,200,600,100);
    tips1->setFont(ft);
    tips1->setText("Click the button below");

    tips2 = new QLabel(this);
    QFont ft1;
    ft1.setPointSize(19);
    tips2->setGeometry(200,300,700,100);
    tips2->setFont(ft);
    tips2->setText("Start your myterious and magical journey!");

    connect(startbutton,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
}

Start::~Start()
{
//    delete ui;
}

void Start::on_pushButton_clicked()
{
    this -> close();
    Widget *w = new Widget;
    w -> show();
}
