#ifndef EMPLOYMENT_H
#define EMPLOYMENT_H
#include "experience.h"

class Employment: public Experience
{
public:
    Employment();
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

#endif // EMPLOYMENT_H
