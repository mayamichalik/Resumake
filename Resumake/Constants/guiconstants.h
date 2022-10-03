#ifndef GUICONSTANTS_H
#define GUICONSTANTS_H

#include <QSize>

class GUIConstants
{
public:
    GUIConstants();
    QSize getDimensions();
    enum PAGE{
        PERSONALINFO,
        EDUANDEXP,
        ADDEXP,
        TEMPLATE,
    };

private:
    const int WIDTH = 660;
    const int HEIGHT = 850;
};

#endif // GUICONSTANTS_H
