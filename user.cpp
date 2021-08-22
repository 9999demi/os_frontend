#include "user.h"

User::User(QString name, QString password, QString sex, QString birthday, QString app)
    : name_(name), password_(password), sex_(sex), birthday_(birthday), app_(app)
{

}

QString User::name() const
{
    return name_;
}

QString User::password() const
{
    return password_;
}

QString User::sex() const
{
    return sex_;
}

QString User::birthday() const
{
    return birthday_;
}


void User::setName(const QString &name)
{
    name_ = name;
}

void User::setPassword(const QString &password)
{
    password_ = password;
}

void User::setSex(const QString &sex)
{
    sex_ = sex;
}

void User::setBirthday(const QString &birthday)
{
    birthday_ = birthday;
}

QString User::app() const
{
    return app_;
}

void User::setApp(const QString &app)
{
    app_ = app;
}
