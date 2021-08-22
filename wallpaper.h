#ifndef WALLPAPER_H
#define WALLPAPER_H

#include <QDialog>

namespace Ui {
class WallPaper;
}

class WallPaper : public QDialog
{
    Q_OBJECT

public:
    explicit WallPaper(QWidget *parent = nullptr);
    ~WallPaper();

signals:
    void choose_wallpaper(int t);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

//    void on_pushButton_4_clicked();


private:
    Ui::WallPaper *ui;
};

#endif // WALLPAPER_H
