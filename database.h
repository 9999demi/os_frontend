#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QVector>
#include "user.h"

class Database
{
public:

    static Database *getInstance();

    bool insert(User &user);

    bool find(QString name);

    bool judge(QString name, QString password);

    QString findGender(QString name);
    QString findBirthday(QString name);
    bool changePwd(QString name, QString old, QString newpwd);

//    QString app;
    QString getApp(QString name);
    void updateApp(QString name, QString app);

private:

    Database();

    QSqlDatabase db_;
};

#endif // DATABASE_H
