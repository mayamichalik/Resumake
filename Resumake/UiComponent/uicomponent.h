#ifndef UICOMPONENT_H
#define UICOMPONENT_H
#include <QVector>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>


class UiComponent: public QObject
{
public:
    UiComponent();
    virtual void render(QBoxLayout * layout);
    virtual QVector<QString> getInput();
    virtual int getInput(int);
    virtual void setInput(QVector<QString> inputs);
    virtual void setInput(int id);

};

#endif // UICOMPONENT_H
