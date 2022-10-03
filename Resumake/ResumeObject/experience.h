#ifndef EXPERIENCE_H
#define EXPERIENCE_H
#include <QString>

class Experience
{
public:
    Experience();
    virtual void setLocation(QString s) = 0;
    virtual void setPosition(QString s) = 0;
    virtual void setDate(QString s)= 0;
    virtual void setDescription(QString s)= 0;
    virtual void setType(QString s)= 0;
    virtual void reset() = 0 ;
    virtual QString getLocation()= 0;
    virtual QString getPosition()= 0;
    virtual QString getDate()= 0;
    virtual QString getDescription()= 0;
    virtual QString getType()= 0;
protected:
    QString location;
    QString position;
    QString date;
    QString description;
    QString type;



};

#endif // EXPERIENCE_H
