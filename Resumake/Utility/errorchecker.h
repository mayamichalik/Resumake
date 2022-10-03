#ifndef ERRORCHECKER_H
#define ERRORCHECKER_H

#include <regex>
#include <QString>

using namespace std;

class ErrorChecker
{
public:
    ErrorChecker();

    bool checkName(QString);

    bool checkEmail(QString);
    bool checkPhone(QString);

    bool checkInstitution(QString);
    bool checkDate(QString);

    bool checkDescription(QString);

    bool checkLength(QString s);
    bool checkLongString(QString s);

private:
    string stringify(QString);
};

#endif //ERRORCHECKER_H
