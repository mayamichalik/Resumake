#include "IO.h"

#include <QJsonValue>
#include <QFile>
IO::IO(){
}
void IO::createJSON(Resume res, QString file){

    IO::educationInfo.insert("Institution : ", QJsonValue(res.getEducation().getInstitutionName()));
    IO::educationInfo.insert("Enrollment : ", QJsonValue(res.getEducation().getEnrollmentDate()));
    IO::educationInfo.insert("Graduation : ", QJsonValue(res.getEducation().getGraduationDate()));
    IO::educationInfo.insert("Description : ", QJsonValue(res.getEducation().getDescription()));
    IO::resInfo.insert("Education: ", IO::educationInfo);

    IO::personalInfo.insert("Name : ", QJsonValue(res.getPersonalInfo().getName()));
    IO::personalInfo.insert("Email : ", QJsonValue(res.getPersonalInfo().getEmail()));
    IO::personalInfo.insert("Phone : ", QJsonValue(res.getPersonalInfo().getPhoneNumber()));
    IO::personalInfo.insert("Github : ", QJsonValue(res.getPersonalInfo().getGithub()));
    IO::personalInfo.insert("Linkedin : ", QJsonValue(res.getPersonalInfo().getLinkedIn()));
    IO::personalInfo.insert("Name : ", QJsonValue(res.getPersonalInfo().getWebsite()));
    IO::resInfo.insert("Personal Info: ", IO::personalInfo);

    IO::experienceInfo.insert("Type : ", QJsonValue(res.getExperience().getType()));
    IO::experienceInfo.insert("Position : ", QJsonValue(res.getExperience().getPosition()));
    IO::experienceInfo.insert("Location : ", QJsonValue(res.getExperience().getLocation()));
    IO::experienceInfo.insert("Date : ", QJsonValue(res.getExperience().getDate()));
    IO::experienceInfo.insert("Description : ", QJsonValue(res.getExperience().getDescription()));
    IO::resInfo.insert("Experience: ", IO::experienceInfo);

    IO::skillInfo.insert("Skill : ", QJsonValue(res.getSkill().getSkill()));
    IO::skillInfo.insert("Description : ", QJsonValue(res.getSkill().getDescription()));
    IO::resInfo.insert("Skills: ", IO::skillInfo);

    QFile jsonFile(file);
    jsonFile.open(QFile::WriteOnly);

    QJsonDocument doc(resInfo);
    jsonFile.write(doc.toJson());
    jsonFile.close();
}
QJsonDocument IO::readJSON(QString file){
    QFile jsonFile(file);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
    jsonFile.close();
}
