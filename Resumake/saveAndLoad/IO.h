#ifndef IO_H
#define IO_H
#include <QJsonObject>
#include <QJsonDocument>
#include "ResumeObject/resume.h"
class IO{
public:
    IO();
    QJsonDocument readJSON(QString);
private:
    void createJSON(Resume, QString);
    QJsonObject educationInfo;
    QJsonObject personalInfo;
    QJsonObject skillInfo;
    QJsonObject experienceInfo;
    QJsonObject resInfo;
    QJsonDocument resum;
};

#endif // IO_H
