//#ifndef MAINWINDOW_H
//#define MAINWINDOW_H

//#include <QMainWindow>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

//class MainWindow : public QMainWindow
//{
//    Q_OBJECT

//public:
//    MainWindow(QWidget *parent = nullptr);
//    ~MainWindow();

//private:
//    Ui::MainWindow *ui;
//};
//#endif // MAINWINDOW_H


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMenu>
#include <QColorDialog>
#include <QToolBar>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QDateTime>
#include <QTimer>
#include <QTextEdit>
#include <QMdiSubWindow>
#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QProgressBar>
#include <QPainter>
#include <QImage>
#include <QTime>
#include <ctime>
#include <QButtonGroup>
#include <QKeyEvent>
#include <QStyle>

#include "ram.h"
#include "rom.h"
#include "appstore.h"
#include "map.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int *mem_arr;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void MySlot();

    Appstore *appstore;

private slots:
    void updata_time();
    void exitb();

    void menu_logout();

    void menu_shutdown();

    void change_wallpaper(int i);

    void ROM_click();
    void RAM_click();
    void store_click();
    //App download
    void map_download();
    void chess_download();
    void fish_download();
    void cal_download();
    void snake_download();
    //App uninstall
    void map_uninstall();
    void cal_uninstall();
    void snake_uninstall();
    void chess_uninstall();
    void fish_uninstall();
    //for ROM connection
    void app_rom_change();
    //for details connection
    void set_app_details();

private:
    QLabel *pTimeLabel;
    QPushButton *App1;

    int cal_place;
    int map_place;
    int snake_place;
    int chess_place;
    int fish_place;
    QPushButton *ROM_btn;
    QPushButton *RAM_btn;
    ROM *rom;
    RAM *ram;
    QPushButton *store;
    QPushButton *calendar;
    QPushButton *snake;
    QPushButton *chess;
    QPushButton *fish;
    QPushButton *map;
    int progress_len();
    double app_ROM();

};

#endif // MAINWINDOW_H
