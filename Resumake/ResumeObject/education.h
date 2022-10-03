#ifndef EDUCATION_H
#define EDUCATION_H
#include <QString>

class Education
{
public:
    Education();
    void setInstitutionName(QString s);
    void setEnrollmentDate(QString s);
    void setGraduationDate(QString s);
    void setDescription(QString s);
    void reset();
    QString getInstitutionName();
    QString getEnrollmentDate();
    QString getGraduationDate();
    QString getDescription();

private:
    QString institutionName;
    QString enrollmentDate;
    QString graduationDate;
    QString description;
};

#endif // EDUCATION_H
