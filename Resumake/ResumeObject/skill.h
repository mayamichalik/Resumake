#ifndef SKILL_H
#define SKILL_H
#include <QString>

class Skill
{
public:
    Skill();
    void setSkill(QString s);
    QString getSkill();
    void reset();
private:
    QString skill;
    QString description;
};

#endif // SKILL_H
