#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QDialog>

namespace Ui {
class Account;
}

class Account : public QDialog
{
    Q_OBJECT

public:
    explicit Account(QWidget *parent = nullptr);
    ~Account();

    QString username;
    QString gender;
    QString birthday;

private:
    Ui::Account *ui;

public slots:
    void showUserInfo(QString name);

    void change();
};

#endif // ACCOUNT_H
