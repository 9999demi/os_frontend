#ifndef LOGOUT_H
#define LOGOUT_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class LogOut;
}

class LogOut : public QDialog
{
    Q_OBJECT

public:
    explicit LogOut(QWidget *parent = nullptr);
    ~LogOut();

signals:
    void close_main();

private slots:
    void on_buttonBox_accepted();
    void exitbutton();
//    void logoutbutton();

private:
    QLabel *ques;
    QPushButton *button1;
    QPushButton *button2;
//    Ui::LogOut *ui;
};

#endif // LOGOUT_H
