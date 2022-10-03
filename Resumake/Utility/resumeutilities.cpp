#include "resumeutilities.h"


ResumeUtilities::ResumeUtilities()
{

}


void ResumeUtilities::adapt(GUIConstants::PAGE page){
    switch(page){
        case GUIConstants::PAGE::PERSONALINFO:
            pageAdapter = new PersonalInfoPageAdapter;
            break;
        case GUIConstants::PAGE::EDUANDEXP:
            pageAdapter = new EducationAndExperiencePageAdapter;
            break;
        case GUIConstants::PAGE::ADDEXP:
            pageAdapter = new OptionalPageAdapter;
            break;
         default:
            pageAdapter = new PersonalInfoPageAdapter;
            break;
    }
}

QVector<QString> ResumeUtilities::getStoredInputs(GUIConstants::PAGE page, Resume * resume){
    adapt(page);
    return pageAdapter->getStoredInputs(resume);
}
void ResumeUtilities::updateResume(GUIConstants::PAGE page, Resume * resume, QVector<QString> userInputs){
    adapt(page);
    pageAdapter->updateResume(resume, userInputs);
}
QString ResumeUtilities::validateResume(QVector<QString> userInputs, GUIConstants::PAGE page){
    adapt(page);
    return pageAdapter->validateInput(userInputs);

}

void ResumeUtilities::showPreview(Resume * r){
    FormatterFactory factory;
    PdfFormatter * f = factory.getFormatter(r->getFormatter());
    GUIConstants * gc = new GUIConstants;
    QString html = f->formatResume(r);

    QTextBrowser * tb = new QTextBrowser;
    tb->setWindowTitle("Preview");
    tb->setFixedSize(gc->getDimensions());

    tb->setText(html);
    tb->show();


}
