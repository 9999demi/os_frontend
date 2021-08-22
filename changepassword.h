#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QDialog>

namespace Ui {
class ChangePassword;
}

class ChangePassword : public QDialog
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = nullptr);
    ~ChangePassword();

    QString username;

public slots:
    void getName(QString name);

private slots:
    void on_buttonBox_accepted();



private:
    Ui::ChangePassword *ui;
};

#endif // CHANGEPASSWORD_H
