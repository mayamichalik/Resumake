#ifndef PERSONALINFO_H
#define PERSONALINFO_H
#include <QString>

class PersonalInfo
{
public:
    PersonalInfo();

    void setName(QString s);
    void setPhoneNumber(QString s);
    void setEmail(QString s);
    void setLinkedIn(QString s);
    void setGithub(QString s);
    void setWebsite(QString s);
    void setDescription(QString s);
    void reset();

    QString getName();
    QString getPhoneNumber();
    QString getEmail();
    QString getLinkedIn();
    QString getGithub();
    QString getWebsite();
    QString getDescription();

private:
    QString name;
    QString phoneNumber;
    QString email;
    QString linkedIn;
    QString github;
    QString website;
    QString description;
};

#endif // PERSONALINFO_H
