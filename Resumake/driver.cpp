#include "driver.h"


Driver::Driver()
{
}

void Driver::startApplication(){
    resume = new Resume;
    gui = new Gui;
    gui->initializeResume(resume, new ResumeUtilities);
    gui->show();

}


void Driver::convertToPDF(Resume * r){
    resume = r;
    PersonalInfo p = resume->getPersonalInfo();
    PdfOutput output;
    output.setResume(resume);
    output.outputPdf();
}
