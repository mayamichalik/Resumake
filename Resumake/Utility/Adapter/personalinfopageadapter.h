#ifndef PERSONALINFOPAGEADAPTER_H
#define PERSONALINFOPAGEADAPTER_H

#include "./pageadapter.h"


class PersonalInfoPageAdapter: public PageAdapter
{
public:
    PersonalInfoPageAdapter();
    QString validateInput(QVector<QString> inputs) override;
    void updateResume(Resume * resume, QVector<QString> inputs) override;
    QVector<QString> getStoredInputs(Resume * resume) override;
};

#endif // PERSONALINFOPAGEADAPTER_H
