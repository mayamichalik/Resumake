#ifndef PERSONALINFOPAGE_H
#define PERSONALINFOPAGE_H
#include "uicomponent.h"
#include "horizontalinput.h"

class PersonalInfoPage: public UiComponent
{
public:
    PersonalInfoPage();
    void render(QBoxLayout * layout) override;

    QVector<QString> getInput() override;
    void setInput(QVector<QString> inputs) override;
private:
    // template page elements and functions
    const int NUM_FIELDS = 5;
    HorizontalInput * fields[5];
    QLabel * pageLabel;
    const char * fieldDescriptions[5] = {"Full Name: ", "Email: ", "Phone: ", "Description: ", "Skills: "};
    const char * fieldPlaceholders[5] = {"Tala Buwadi", "tbuwadi@uwo.ca", "519-123-4567",
                                         "What're your career goals/objectives?", "Enter skills separated by commas"};

};

#endif // PERSONALINFOPAGE_H
