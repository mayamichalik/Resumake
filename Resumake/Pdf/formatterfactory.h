#ifndef FORMATTERFACTORY_H
#define FORMATTERFACTORY_H

#include "Constants/pdfconstants.h"
#include "defaultformat.h"
#include "pdfformatter.h"

class FormatterFactory
{
public:
    FormatterFactory();
    PdfFormatter * getFormatter(int);

};

#endif // FORMATTERFACTORY_H
