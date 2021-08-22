#include "database.h"
#include "user.h"
#include <QSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <QSqlDatabase>

Database::Database()
{

    // 1. judge the database exist or not
    if (!QSqlDatabase::contains("test"))
    {
        db_ = QSqlDatabase::addDatabase("QSQLITE", "test");
//        qDebug() << db_.connectionName();

        //set database name
        db_.setDatabaseName("3002.db");
//        qDebug() << db_.databaseName();

    }
    else
    {
        db_ = QSqlDatabase::addDatabase("test");
    }

    // 2. open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        return;
    }

    // 3. create the database table
    QString sql = "create table if not exists users(name varchar(30), password varchar(30), sex varchar(10), birthday varchar(20),app varchar(15));";
    QSqlQuery query(db_);
    if (query.exec(sql))
    {
//        qDebug() << "create table successfully!";
    }
    db_.close();
}

Database *Database::getInstance()
{
    static Database db;
    return &db;
}

bool Database::insert(User &user)
{
    QString sql = QString("insert into users values('%1','%2','%3','%4','%5');")
            .arg(user.name())
            .arg(user.password())
            .arg(user.sex())
            .arg(user.birthday())
            .arg(user.app());
    // 1. open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        return false;
    }

    // 2. excute sql
    QSqlQuery query(db_);
    if (!query.exec(sql))
    {
//        qDebug() << "insert:" << query.lastError().text();
        return false;
    }

    // 3. close the database
    db_.close();
    return true;
}

bool Database::find(QString name)
{
    QString sql = QString("select name from users where name = :xxx;");

    // 1. open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    // 2. excute sql
    QSqlQuery query(db_);
    query.prepare(sql);
    query.bindValue(":xxx", QVariant(name));
    query.exec();

    // 3. if search successfully:
    if (query.next())
    {
        if (name == query.value(0).toString())
        {
            return true;
        }
    }

    // 4. close the database
    db_.close();
    return false;
}

bool Database::judge(QString name, QString password)
{
    QString sql = QString("select name, password from users where name = :xxx;");

    // 1. open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    // 2. excute sql
    QSqlQuery query(db_);
    query.prepare(sql);
    query.bindValue(":xxx", QVariant(name));
    query.exec();

    // 3. check the password
    if (query.next())
    {
        if(!(password == query.value(1).toString()))
        {
            return false;
        }
    }

    // 4. close the database
    db_.close();
    return true;
}

QString Database::findGender(QString name)
{
    QString sql = QString("select sex from users where name = :xxx;");

    // 1. open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    // 2. excute sql
    QSqlQuery query(db_);
    query.prepare(sql);
    query.bindValue(":xxx", QVariant(name));
    query.exec();

    QString tem = "";
    // 3. if search successfully:
    if (query.next())
    {
        tem = query.value(0).toString();
    }

    // 4. close the database
    db_.close();
    return tem;
}

QString Database::findBirthday(QString name)
{
    QString sql = QString("select birthday from users where name = :xxx;");

    // 1. open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    // 2. excute sql
    QSqlQuery query(db_);
    query.prepare(sql);
    query.bindValue(":xxx", QVariant(name));
    query.exec();

    QString tem = "";
    // 3. if search successfully:
    if (query.next())
    {
        tem = query.value(0).toString();
    }

    // 4. close the database
    db_.close();
    return tem;
}

bool Database::changePwd(QString name, QString old, QString newpwd)
{
    QString sql = QString("select name, password from users where name = :xxx;");

    // 1. open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    // 2. excute sql
    QSqlQuery query(db_);
    query.prepare(sql);
    query.bindValue(":xxx", QVariant(name));
    query.exec();

    // 3. check the password
    if (query.next())
    {
        if(!(old == query.value(1).toString()))
        {
            return false;
        }
    }

    //4.update the password
    QString sql1 = QString("update users set password = ? where name = ?");
    QSqlQuery query1(db_);
    query1.prepare(sql1);
    query1.addBindValue(newpwd);
    query1.addBindValue(name);
    query1.exec();


    // 5. close the database
    db_.close();
    return true;
}

QString Database::getApp(QString name)
{
    QString sql = QString("select app from users where name = :xxx;");

    // 1. open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    // 2. excute sql
    QSqlQuery query(db_);
    query.prepare(sql);
    query.bindValue(":xxx", QVariant(name));
    query.exec();

    QString tem = "";
    // 3. if search successfully:
    if (query.next())
    {
        tem = query.value(0).toString();
    }

    // 4. close the database
    db_.close();
    return tem;
}

void Database::updateApp(QString name, QString app)
{
    QString sql = QString("update users set app = ? where name = ?");

    // open the database
    if (!db_.open())
    {
//        qDebug() << "open:" << db_.lastError().text();
        exit(-1);
    }

    QSqlQuery query(db_);
    query.prepare(sql);
    query.addBindValue(app);
    query.addBindValue(name);
    query.exec();

//    qDebug() << app;
    // 5. close the database
    db_.close();
}
