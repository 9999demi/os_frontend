#ifndef FISHJOY_H
#define FISHJOY_H

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

class Fishjoy : public QWidget
{
    Q_OBJECT
public:
    explicit Fishjoy(QWidget *parent = nullptr);
    QPushButton *fish;
signals:

public slots:
};

#endif // FISHJOY_H
