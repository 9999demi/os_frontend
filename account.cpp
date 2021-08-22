#include "account.h"
#include "ui_account.h"
#include "database.h"
#include "changepassword.h"

Account::Account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Account)
{
    ui->setupUi(this);
    this -> setWindowTitle("Account");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(change()));
}

Account::~Account()
{
    delete ui;
}

void Account::showUserInfo(QString name)
{
//    ui->lineEdit->setText(name);
    ui->label_4->setText(name);
    username = name;

    //search gender and birthday by the given username
    Database *db = Database::getInstance();
    gender = db->findGender(name);
    birthday = db->findBirthday(name);
    ui->label_5->setText(gender);
    ui->label_6->setText(birthday);
}

void Account::change()
{
    ChangePassword c;
    c.getName(username);
    c.exec();
}
