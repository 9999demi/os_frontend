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
#include <QProcess>
#include <QDebug>
#include <QThread>
#include <QString>
#include <QtConcurrent>

#include "ram.h"
#include "rom.h"
#include "appstore.h"
#include "map.h"
#include "filemanager.h"
#include "map_app.h"
#include "database.h"
#include "file_run.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int *mem_arr;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void MySlot();
    void summation();
    int getMemory();

    Appstore *appstore;
    FileManager *file_manager;
    map_app *map_app_UI;


private slots:
    void updata_time();
    void exitb();

    void menu_logout();

    void menu_shutdown();

    void change_wallpaper(int i);

    void ROM_click();
    void RAM_click();
    void store_click();

    //to create QProcess objects
//    void map_clicked();
    void snake_clicked();
    void chess_clicked();
    void fish_clicked();
    void calendar_clicked();

    //Memory communications
    void readOut_snake();
    void readOut_fish();
    void readOut_chess();
    void readOut_calendar();

    void receive_memory_snake(int data);
    void receive_memory_fish(int data);
    void receive_memory_chess(int data);
    void receive_memory_calendar(int data);

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
    void file_system_click();
    void receiveUserName(QString name);
    void map_app_click();
    void displayApp(QString application);
    void showApp(QString i);

signals:
    void send_memory_snake(int data);
    void send_memory_fish(int data);
    void send_memory_chess(int data);
    void send_memory_calendar(int data);

    void send_to_ram_snake(int data);
    void send_to_ram_fish(int data);
    void send_to_ram_chess(int data);
    void send_to_ram_calendar(int data);
    void send_to_ram_total(int data);

private:
    QString app;
    Database *db;
    QLabel *pTimeLabel;
    QPushButton *App1;
    QPushButton *File_system;

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
    QString user;

};

#endif // MAINWINDOW_H
