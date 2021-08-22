#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QWidget>
#include <QDir>
#include <QListWidget>
#include <QProcess>

namespace Ui {
class FileSystem;
}

class FileSystem : public QWidget
{
    Q_OBJECT

public:
    explicit FileSystem(QWidget *parent = nullptr);
    ~FileSystem();


private:
    Ui::FileSystem *ui;
};

#endif // FILESYSTEM_H
