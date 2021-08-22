#ifndef START_H
#define START_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void on_pushButton_clicked();

private:
    QPushButton *startbutton;
    QLabel *tips1;
    QLabel *tips2;
//    Ui::Start *ui;
};

#endif // START_H
