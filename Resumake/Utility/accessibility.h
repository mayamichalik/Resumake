#ifndef ACCESSIBILITY_H
#define ACCESSIBILITY_H
#include <QApplication>
#include <QFile>

class Accessibility
{
public:
    Accessibility();
    void setNormal(QApplication *q);
    void setAccessible(QApplication *q);
};

#endif // ACCESSIBILITY_H
