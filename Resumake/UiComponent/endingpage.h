#ifndef ENDINGPAGE_H
#define ENDINGPAGE_H

#include "uicomponent.h"


class EndingPage: public UiComponent
{
    Q_OBJECT;
public:
    EndingPage();
    void render(QBoxLayout * layout) override;

private:
    QLabel * titleLabel;
};

#endif // ENDINGPAGE_H
