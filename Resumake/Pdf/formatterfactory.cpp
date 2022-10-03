#include "formatterfactory.h"

FormatterFactory::FormatterFactory()
{

}


PdfFormatter * FormatterFactory::getFormatter(int id){


    // please change the factory algorithm when more formats are added

    PdfFormatter * f = new DefaultFormatter();

    return f;
}
