#ifndef TEMPLATEPAGE_H
#define TEMPLATEPAGE_H

#include "uicomponent.h"
#include "Constants/pdfconstants.h"
#include "Utility/resumeutilities.h"

class TemplatePage: public UiComponent
{
public:
    TemplatePage();
    void render(QBoxLayout * layout) override;
    void setInput(int id) override;
    int getInput(int) override;
private slots:
     void setSelected();
private:

    int selectedFormatter = 0;
    QVBoxLayout * pageLayout;
    QPushButton * formatters[PDFConstants::NUM_FORMATTER];
    QLabel * pageLabel;

};

#endif // TEMPLATEPAGE_H
