#ifndef EDUCATIONANDEXPERIENCEPAGEADAPTER_H
#define EDUCATIONANDEXPERIENCEPAGEADAPTER_H
#include "./pageadapter.h"

class EducationAndExperiencePageAdapter: public PageAdapter
{
public:
    EducationAndExperiencePageAdapter();
    QString validateInput(QVector<QString> inputs) override;
    void updateResume(Resume * resume, QVector<QString> inputs) override;
    QVector<QString> getStoredInputs(Resume * resume) override;
private:
    Employment createExperience(QString position, QString location, QString date, QString description, QString type);
};

#endif // EDUCATIONANDEXPERIENCEPAGEADAPTER_H
