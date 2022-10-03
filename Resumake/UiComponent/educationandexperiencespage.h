#ifndef EDUCATIONANDEXPERIENCESPAGE_H
#define EDUCATIONANDEXPERIENCESPAGE_H

#include "uicomponent.h"
#include "horizontalinput.h"

class EducationAndExperiencesPage: public UiComponent
{
public:
    EducationAndExperiencesPage();
    void render(QBoxLayout * layout) override;

    QVector<QString> getInput() override;
    void setInput(QVector<QString> inputs) override;

private:

    //education and experience specifics
    void createWorkExperienceSection();
    void createEducationExperienceSection();

    QVBoxLayout * experienceBoxes[2];
    QLabel * employmentLabel;
    QLabel * educationLabel;
    const char * workExperienceDescriptions[4] = {"Company/Organization: ","Job Title: ", "Date: ", "Responsibilities: "};
    const char * educationExperienceDescriptions[4] ={"Institution: ", "Degree: ", "Enrollment date: ", "Graduation date: "};

    HorizontalInput * companyName;
    HorizontalInput * jobTitle;
    HorizontalInput * jobDate;
    HorizontalInput * jobResponsibilities;

    HorizontalInput * educationName;
    HorizontalInput * degree;
    HorizontalInput * educationDate;
    HorizontalInput * educationGDate;

};

#endif // EDUCATIONANDEXPERIENCESPAGE_H
