#include "changepassword.h"
#include "ui_changepassword.h"
#include "database.h"
#include <QMessageBox>

ChangePassword::ChangePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    this -> setWindowTitle("Change Password");
}

ChangePassword::~ChangePassword()
{
    delete ui;
}


void ChangePassword::on_buttonBox_accepted()
{
    QString old = ui->lineEdit->text();
    QString newpwd = ui->lineEdit_2->text();
    Database *db = Database::getInstance();
    bool tf = db->changePwd(username, old, newpwd);
    if (tf == false)
    {
        QMessageBox::warning(this,tr("Warning"),tr("Failed! Invalid password!"));
    } else
    {
        QMessageBox::information(this,"Tips","Change successfully!",QMessageBox::Ok);
    }
}

void ChangePassword::getName(QString name)
{
    username = name;
}
