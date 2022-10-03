#include "gui.h"

class Driver{
public:
    void convertToPDF(Resume * r);
};

Driver * driver;
Accessibility * accessible;

Gui::Gui(QWidget *parent) : QDialog(parent)
{
    gc = new GUIConstants;
    mainLayout = new QVBoxLayout;
    driver = new Driver;
    state = 0;
    setLayout(mainLayout);
    setFixedSize(gc->getDimensions());
    setWindowTitle(tr("Resumake"));
    renderDisplay();
}

void Gui::initializeResume(Resume *r, ResumeUtilities *rr){
    resume = r;
    ru = rr;
}

void Gui::clearLayout(QLayout * layout)
{
    //recursive layout removal
    // removes all deeply nested widgets and layout
    if(!layout){
        return;
    }
    while(auto item = layout->takeAt(0)){
        delete item->widget();
        if(item->layout() != nullptr){
            clearLayout(item->layout());
        }
        delete item->layout();
    }

}

void Gui::restartGui(){
    state= 0;
    resume->reset();
    renderDisplay();
}

void Gui::renderDisplay(){

   clearLayout(mainLayout);
   if(state == 0){
       displayingComponent = new TitlePage;
       createStartButton();
       createHelpButton();
       createMenuButtons();

   }else if(state == 1){
       displayingComponent = new PersonalInfoPage;
       createMenuButtons();
       mainLayout->addLayout(MenuLayout);
   }else if(state == 2){
       displayingComponent = new EducationAndExperiencesPage;
       createMenuButtons();
       mainLayout->addLayout(MenuLayout);
   }else if(state == 3){
        displayingComponent = new OptionalExperiencesPage;
        createMenuButtons();
        mainLayout->addLayout(MenuLayout);
   }else if(state ==4){
       displayingComponent = new TemplatePage;
       createMenuButtons();
       mainLayout->addLayout(MenuLayout);
   }else{
       ru->showPreview(resume);
       convertButton = new QPushButton("Convert to PDF", this);
       prevButton = new QPushButton("Back", this);
       restartButton = new QPushButton("Restart", this);

       connect(convertButton, &QPushButton::clicked, this, &Gui::convert);
       connect(restartButton, &QPushButton::clicked, this, &Gui::restartGui);
       connect(prevButton, &QPushButton::clicked, this, &Gui::updateGui);
       displayingComponent = new EndingPage;

       displayingComponent->render(mainLayout);
       mainLayout->addWidget(convertButton);
       mainLayout->addWidget(prevButton);
       mainLayout->addWidget(restartButton);
       createMenuButtons();
       mainLayout->addLayout(MenuLayout);
       return;
   }
   if(state != 0)
        restoreInfo();
   displayingComponent->render(mainLayout);
   if(state == 0){
       mainLayout->addWidget(startButton);
       mainLayout->addWidget(helpButton);
       mainLayout->addLayout(MenuLayout);
   }else{
       createDirectionalButtons();
       mainLayout->addLayout(buttonLayout);
   }

}
void Gui::createStartButton(){
    startButton = new QPushButton("Start");
    connect(startButton, &QPushButton::clicked, this, &Gui::updateGui);
}

void Gui::createHelpButton(){
    helpButton = new QPushButton("Help");
    connect(helpButton, &QPushButton::clicked, this, &Gui::help);
}
void Gui::createMenuButtons(){
    MenuLayout = new QHBoxLayout;
    closeButton = new QPushButton("Quit", this);
    accessiblityButton = new QPushButton("Change Mode", this);
    connect(closeButton, &QPushButton::clicked, this, &Gui::confirmQuit);
    connect(accessiblityButton, &QPushButton::clicked, this, &Gui::changeMode);
    MenuLayout->addWidget(accessiblityButton);
    MenuLayout->addWidget(closeButton);

}

void Gui::createDirectionalButtons(){
    buttonLayout = new QHBoxLayout;
    nextButton = new QPushButton("Next", this);
    connect(nextButton, &QPushButton::clicked, this, &Gui::updateGui);

    prevButton = new QPushButton("Back", this);
    connect(prevButton, &QPushButton::clicked, this, &Gui::updateGui);
    buttonLayout->addWidget(prevButton);
    buttonLayout->addWidget(nextButton);
    createMenuButtons();
}

void Gui::errorMessage(QString message){
    QMessageBox errorBox;
    errorBox.setText(message);
    errorBox.exec();
}

void Gui::confirmQuit(){
    QMessageBox::StandardButton yesOrNoBox;
    yesOrNoBox = QMessageBox::question(this, "Resumake", "Are you sure you want to quit? Progress will not be saved!", QMessageBox::Yes| QMessageBox::No);

    if(yesOrNoBox == QMessageBox::Yes){
       Gui::close();
    }
}
void Gui::help(){
    QMessageBox helpBox;
    helpBox.setText("Resumake is a simple resume maker.");
    helpBox.exec();
}

void Gui::convert(){

    errorMessage("Converting your info to pdf!");
    driver->convertToPDF(resume);
    QString outputPath = QDir::currentPath() + "/"+ resume->getPersonalInfo().getName() + "-resume.pdf";
    errorMessage("Rusume saved to: " + outputPath);

}

int i = -1;
void Gui::changeMode(){
    if(i==-1){
        //accessibility mode first time
        i=0;
    }
    if(i==0){
        //accessibility mode
        i=1;
        accessible->setAccessible(qApp);
    }else if(i==1){
        //regular mode
        i=0;
        accessible->setNormal(qApp);
    }
}

GUIConstants::PAGE Gui::getPageConstant(int state){
    switch(state){
    case 1:
        return gc->PAGE::PERSONALINFO;
    case 2:
        return gc->PAGE::EDUANDEXP;
    case 3:
        return gc->PAGE::ADDEXP;
    case 4:
        return gc->PAGE::TEMPLATE;
    default:
        return gc->PAGE::PERSONALINFO;
    }
}

void Gui::updateGui(){

    if(sender() == startButton){
        state++;
        renderDisplay();
        return;
    }

    auto userInputs = displayingComponent->getInput();

    if(sender() == nextButton){
        if(state == 4){
            int f = displayingComponent->getInput(1);
            resume->setFormatter(f);
        }else{
            QString validationResult = ru->validateResume(userInputs, getPageConstant(state));
            if(validationResult.length() != 0){
                errorMessage(validationResult);
                return;
            }
            ru->updateResume(getPageConstant(state), resume, userInputs);
        }
    }
    state += sender() == nextButton? 1 : -1;
    renderDisplay();
}

void Gui::restoreInfo(){

    if(state == 4){
        displayingComponent->setInput(0);
    }else{
       displayingComponent->setInput(ru->getStoredInputs(getPageConstant(state), resume));
    }

}


