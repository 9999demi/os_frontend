#include "shutdown.h"
#include "ui_shutdown.h"

ShutDown::ShutDown(QWidget *parent) :
    QDialog(parent)
//    ui(new Ui::ShutDown)
{
    this->resize(380,200);
    this->setWindowTitle("Log Out");
    ques = new QLabel(this);
    ques->setText("Are you sure to\nshut down the system?");
    ques->setStyleSheet("font-size:17px");
    ques->setGeometry(QRect(50,50,300,60));

    button1 = new QPushButton(this);
    button1->setText("Shut Down");
    button1->setGeometry(QRect(70,120,100,30));

    button2 = new QPushButton(this);
    button2->setText("Cancel");
    button2->setGeometry(QRect(200,120,100,30));
//    ui->setupUi(this);

    this->connect(button2,SIGNAL(clicked()),this,SLOT(exitbutton()));
    this->connect(button1,SIGNAL(clicked()),this,SLOT(on_buttonBox_accepted()));
}

ShutDown::~ShutDown()
{
//    delete ui;
}

void ShutDown::exitbutton(){
    this->close();
}

void ShutDown::on_buttonBox_accepted()
{
    this -> close();
    emit shut_main();
}
