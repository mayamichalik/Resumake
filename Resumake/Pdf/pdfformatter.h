#ifndef PDFFORMATTER_H
#define PDFFORMATTER_H

#include <QString>
#include "../ResumeObject/resume.h"

class PdfFormatter
{
public:
    virtual QString formatResume(Resume * resume)=0;
    virtual ~PdfFormatter(){};
};

#endif // PDFFORMATTER_H