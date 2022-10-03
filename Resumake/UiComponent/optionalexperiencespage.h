#ifndef OPTIONALEXPERIENCESPAGE_H
#define OPTIONALEXPERIENCESPAGE_H

#include "uicomponent.h"
#include "horizontalinput.h"

class OptionalExperiencesPage: public UiComponent
{
public:
    OptionalExperiencesPage();
    void render(QBoxLayout * layout) override;

    QVector<QString> getInput() override;
    void setInput(QVector<QString> inputs) override;


private:

    void createWorkExperiencesSection();

    QVBoxLayout * experienceBoxes[2];
    QLabel * label;
    const char * workExperienceDescriptions[4] = {"Company/Organization: ","Job Title: ", "Date: ", "Responsibilities: "};

    HorizontalInput * fields[8];
    const int NUM_FIELDS = 8;
};

#endif // OPTIONALEXPERIENCESPAGE_H
