#include <QString>
#include "defaultformat.h"

DefaultFormatter::DefaultFormatter()
{

}
DefaultFormatter::~DefaultFormatter(){

}

QString DefaultFormatter::formatResume(Resume * resume){

QString html ="";
html += "<div align=center><h1>"+resume->getPersonalInfo().getName()+"</h1></div>";
html += "<div align=center>"+resume->getPersonalInfo().getPhoneNumber()+"</div>";
html += "<div align=center>"+resume->getPersonalInfo().getEmail()+"</div>";

html += "<hr>";
html+= "<div align=left>Professional Objective: "+resume->getPersonalInfo().getDescription()+"</div>";

html += "<hr>";
html+= "<div align=left>Skills</div>";
html+= "<ul>";
auto skills = resume->getSkills();
for(auto skill : skills){
    html+= "<li>"+skill.getSkill()+"</li>";
}
html+="</ul>";

html += "<hr>";
html += "<h2>Education Experience</h2>";
html += "<div align=left>School Name: "+resume->getEducation().getInstitutionName()+"</div>";
html += "<div align=left>Enrollment Date: "+resume->getEducation().getEnrollmentDate()+"</div>";
html += "<div align=left>Graduation Date: "+resume->getEducation().getGraduationDate()+"</div>";
html += "<div align=left>Description: "+resume->getEducation().getDescription()+"</div>";


html += "<hr>";
html += "<h2>Work Experience</h2>";

auto experiences = resume->getExperiences();

for(int i = 0; i < 3; i ++){
    auto exp = experiences[i];
    if(exp.getLocation().length() != 0){
        html += "<div align=left>Company Name: "+exp.getPosition()+"</div>";
        html += "<div align=left>Job Title: "+exp.getLocation()+"</div>";
        html += "<div align=left>Employment Date: "+exp.getDate()+"</div>";
        html += "<div align=left>Description: "+exp.getDescription()+"</div>";
        html += "<br>";
    }
}





return html;

}
