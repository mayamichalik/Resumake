#ifndef HORIZONTALINPUT_H
#define HORIZONTALINPUT_H
#include "uicomponent.h"

class HorizontalInput : public UiComponent
{
public:
    HorizontalInput(QString labelText, QString placeholder);
    void render(QBoxLayout * layout) override;
    QString getUserInput();
    void setUserInput(QString s);
private:
    QVBoxLayout * boxLayout;
    QLabel *label;
    QLineEdit * lineEdit;

};

#endif // HORIZONTALINPUT_H
