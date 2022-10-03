#ifndef DEFAULTFORMATTER_H
#define DEFAULTFORMATTER_H

#include <QString>
#include "pdfformatter.h"

class DefaultFormatter: public PdfFormatter
{
public:
    QString formatResume(Resume * resume);
    DefaultFormatter();
    ~DefaultFormatter();
};

#endif // DEFAULTFORMATTER_H