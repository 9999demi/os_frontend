#ifndef CHESS_H
#define CHESS_H

#include <QWidget>
#include <QIcon>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QPushButton>
#include <QMessageBox>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QTime>
#include <ctime>
#include <QButtonGroup>
#include <QKeyEvent>
#include <QStyle>
#include <QLabel>
#include <QString>
#include <QPlainTextEdit>
#include <QProgressBar>
#include <QThread>

class Chess : public QWidget
{
    Q_OBJECT
public:
    explicit Chess(QWidget *parent = nullptr);
    QPushButton *chess;
signals:

public slots:
};

#endif // CHESS_H
