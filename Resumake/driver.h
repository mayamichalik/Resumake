#ifndef DRIVER_H
#define DRIVER_H

#include "ResumeObject/resume.h"
#include "gui.h"
#include "Utility/resumeutilities.h"
#include "Pdf/pdfoutput.h"

class Driver
{

public:
    Driver();
    void startApplication();
    void convertToPDF(Resume * r);

private:
    Gui * gui;
    Resume * resume;

};

#endif // DRIVER_H
