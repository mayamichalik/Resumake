#ifndef VOLUNTEER_H
#define VOLUNTEER_H
#include "experience.h"

class Volunteer: public Experience
{
public:
    Volunteer();
    void setLocation(QString s) override;
    void setPosition(QString s) override;
    void setDate(QString s) override;
    void setDescription(QString s) override;
    void setType(QString s) override;
    void reset() override;
    QString getLocation() override;
    QString getPosition() override;
    QString getDate() override;
    QString getDescription() override;
    QString getType() override;
};

#endif // VOLUNTEER_H
