#ifndef GUI_H
#define GUI_H

#include <QVBoxLayout>
#include <QDialog>
#include <QDir>
#include "UiComponent/uicomponent.h"
#include "UiComponent/titlepage.h"
#include "UiComponent/personalinfopage.h"
#include "UiComponent/educationandexperiencespage.h"
#include "UiComponent/optionalexperiencespage.h"
#include "UiComponent/templatepage.h"
#include "UiComponent/endingpage.h"
#include <QVector>
#include "ResumeObject/resume.h"
#include "Utility/resumeutilities.h"
#include "Utility/accessibility.h"
#include "Constants/guiconstants.h"

class Gui: public QDialog
{

public:
    Gui(QWidget * parent = 0);
    void renderDisplay();
    void initializeResume(Resume * r, ResumeUtilities * rr);
private slots:
    void updateGui();
    void confirmQuit();
    void changeMode();
    void help();
    void convert();
private:
    int state;
    const int LAST_STATE = 5;
    void restoreInfo();
    void clearLayout(QLayout * layout);
    void createDirectionalButtons();
    void createStartButton();
    void createHelpButton();
    void createMenuButtons();
    void errorMessage(QString message);
    void restartGui();
    GUIConstants::PAGE getPageConstant(int);
    QBoxLayout* mainLayout;
    UiComponent * displayingComponent;
    QHBoxLayout * buttonLayout;
    QHBoxLayout * MenuLayout;
    QPushButton * startButton;
    QPushButton * nextButton;
    QPushButton * prevButton;
    QPushButton * helpButton;
    QPushButton * restartButton;
    QPushButton * closeButton;
    QPushButton * convertButton;
    QPushButton * accessiblityButton;
    Resume * resume;
    ResumeUtilities * ru;
    GUIConstants * gc;
};

#endif // GUI_H
