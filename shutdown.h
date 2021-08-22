#ifndef SHUTDOWN_H
#define SHUTDOWN_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class ShutDown;
}

class ShutDown : public QDialog
{
    Q_OBJECT

public:
    explicit ShutDown(QWidget *parent = nullptr);
    ~ShutDown();

signals:
    void shut_main();

private slots:
    void on_buttonBox_accepted();
    void exitbutton();

private:
    QPushButton *button1;
    QPushButton *button2;
    QLabel *ques;
//    Ui::ShutDown *ui;
};

#endif // SHUTDOWN_H
