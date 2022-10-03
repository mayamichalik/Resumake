#ifndef PAGEADAPTER_H
#define PAGEADAPTER_H

#include "ResumeObject/resume.h"
#include "Utility/errorchecker.h"
#include "Constants/errormessages.h"
#include <QVector>
#include <QString>
#include <QStringList>

class PageAdapter
{

public:
    PageAdapter();
    virtual QString validateInput(QVector<QString> inputs) =0;
    virtual void updateResume(Resume * resume, QVector<QString> inputs)=0;
    virtual QVector<QString> getStoredInputs(Resume * resume)=0;
protected:
    ErrorChecker * ec = new ErrorChecker;
    ErrorMessages * em = new ErrorMessages;
};

#endif // PAGEADAPTER_H
