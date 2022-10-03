#ifndef TITLEPAGE_H
#define TITLEPAGE_H
#include "uicomponent.h"

class TitlePage: public UiComponent
{
public:
    TitlePage();
    void render(QBoxLayout * layout) override;

private slots:
    void help();
private:
    // title page elements and functions
    void createTitle();
    QLabel *appTitle;
};

#endif // TITLEPAGE_H
