#ifndef PDFCONSTANTS_H
#define PDFCONSTANTS_H

#include <QString>

class PDFConstants
{
public:
    PDFConstants();
    const static int NUM_FORMATTER = 4;

    static QString getFormatterName(int id){
        QString formatterName[4] = {"Default", "Professional", "Casual", "Comic Sans?"};
        return formatterName[id];
    }
};

#endif // PDFCONSTANTS_H
