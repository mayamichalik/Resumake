#ifndef OPTIONALPAGEADAPTER_H
#define OPTIONALPAGEADAPTER_H

#include "./pageadapter.h"

class OptionalPageAdapter: public PageAdapter
{
public:
    OptionalPageAdapter();
    QString validateInput(QVector<QString> inputs) override;
    void updateResume(Resume * resume, QVector<QString> inputs) override;
    QVector<QString> getStoredInputs(Resume * resume) override;
private:
    Employment createExperience(QString position, QString location, QString date, QString description, QString type);
};

#endif // OPTIONALPAGEADAPTER_H
