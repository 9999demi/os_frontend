#ifndef USER_H
#define USER_H
#include <QString>
class User
{
public:
    User(QString name="", QString password="", QString sex="", QString birthday="", QString app="");
    QString name() const;
    void setName(const QString &name);

    QString password() const;
    void setPassword(const QString &password);

    QString sex() const;
    void setSex(const QString &sex);

    QString birthday() const;
    void setBirthday(const QString &birthday);

    QString app() const;
    void setApp(const QString &app);
private:
    QString app_;
    QString name_;
    QString password_;
    QString sex_;
    QString birthday_;
};

#endif // USER_H
