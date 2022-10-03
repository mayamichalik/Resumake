#ifndef RESUMEUTILITIES_H
#define RESUMEUTILITIES_H
#include "ResumeObject/resume.h"
#include "Adapter/pageadapter.h"
#include "Adapter/educationandexperiencepageadapter.h"
#include "Adapter/optionalpageadapter.h"
#include "Adapter/personalinfopageadapter.h"
#include "Constants/guiconstants.h"
#include <QTextBrowser>
#include "Pdf/formatterfactory.h"

class ResumeUtilities
{
public:
    ResumeUtilities();
    QVector<QString> getStoredInputs(GUIConstants::PAGE page, Resume * resume);
    void updateResume(GUIConstants::PAGE page, Resume * resume, QVector<QString> userInputs);
    QString validateResume(QVector<QString> userInputs, GUIConstants::PAGE page);
    void showPreview(Resume * r);
private:
    PageAdapter * pageAdapter;
    void adapt(GUIConstants::PAGE page);

};

#endif // RESUMEUTILITIES_H
