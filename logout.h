#ifndef LOGOUT_H
#define LOGOUT_H

#include <QDialog>

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

private:
    Ui::LogOut *ui;
};

#endif // LOGOUT_H
