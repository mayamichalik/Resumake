#ifndef OTHEREXPERIENCE_H
#define OTHEREXPERIENCE_H
#include "experience.h"

class OtherExperience : public Experience
{
public:
    OtherExperience();
    void setHeading(QString s);
    QString getHeading();
    bool isNewSection();

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

private:
    QString heading;
    bool newSection;
};

#endif // OTHEREXPERIENCE_H
