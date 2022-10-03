#ifndef PDFOUTPUT_H
#define PDFOUTPUT_H

#include <memory>
#include <QString>
#include "../ResumeObject/resume.h"
#include "formatterfactory.h"
#include <QApplication>
#include <QtCore>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QString>
#include <QTextDocument>
#include "Constants/guiconstants.h"

class PdfOutput
{
public:
    PdfOutput();
    void selectOutputDir();
    void setResume(Resume * resume);
    void outputPdf();
private:
    Resume * userResume;
    QString selectedOutputDir;
    FormatterFactory * factory;
    PdfFormatter * formatter;
    
};

#endif // PDFOUTPUT_H
