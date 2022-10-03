#ifndef ERRORMESSAGES_H
#define ERRORMESSAGES_H
#include <QString>

class ErrorMessages
{
public:
    ErrorMessages();
    QString getErrorMessage(int messageNum);
private:
    QString * errorMessages[9] = {
        new QString("Unable to proceed, enter a first and last name"),
        new QString("Unable to proceed, check email"),
        new QString("Unable to proceed, check phone"),
        new QString("Unable to proceed, check description"),
        new QString("Unable to proceed, check skills"),
        new QString("Unable to proceed, check company or institution name"),
        new QString("Unable to proceed, check job title and degree"),
        new QString("Unable to proceed, check date on employment and education"),
        new QString("Unable to proceed, check job description"),
    };
};

#endif // ERRORMESSAGES_H
