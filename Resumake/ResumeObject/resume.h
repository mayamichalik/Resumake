#ifndef RESUME_H
#define RESUME_H
#include <QString>
#include "personalinfo.h"
#include "experience.h"
#include "employment.h"
#include "otherexperience.h"
#include "education.h"
#include "skill.h"
#include "volunteer.h"
#include <QVector>

class Resume
{
public:
    Resume();
    Education getEducation();
    QVector<Skill>  getSkills();
    QVector<Employment> getExperiences();
    PersonalInfo getPersonalInfo();

    void updatePersonalInfo(QString name, QString phone, QString email, QString description, QString linkedIn, QString github, QString website);
    void setEducation(QString name, QString description, QString date, QString gdate);
    void setExperiences(QVector<Employment> emp);
    void setSkills(QVector<Skill>);
    void reset();
    void setFormatter(int);

    int getFormatter();
private:
    Education education;
    PersonalInfo personalInfo;
    QVector<Skill> skills;
    QVector<Employment> experiences;
    int formatterId;
};

#endif // RESUME_H
