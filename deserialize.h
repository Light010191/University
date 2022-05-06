#pragma once

#include <string>

#include "cli.h"
#include "Date.h"

using namespace std;

Date get_date(string str) { // str = "dd.mm.yyyy";
    auto temp = Parse(str, ".");
    Date date(stoi(temp[2]), stoi(temp[1]), stoi(temp[0]));
    return date;
}

Student get_student(string str) { // str = "title|content|done|dd.mm.yyyy";
    auto temp = Parse(str, "|");
    Faculty select_subject;
    if (temp[5] == "Design") {
        select_subject = Faculty::Design;
    }
    else{
        select_subject = Faculty::SoftDev;
    }    

    Date birth = get_date(temp[3]);
    Student student(temp[0], temp[1], birth, temp[3], temp[4], select_subject);
    return student;
}

Teacher get_teacher(string str) { // str = "title|content|done|dd.mm.yyyy";
    auto temp = Parse(str, "|");
    Subjects select_subject;
    if (temp[5] == "Programming") {
        select_subject.push_back(Subject::Programming);
    }
    if(temp[5] == "UI") {
        select_subject.push_back(Subject::UI);
    }
    if(temp[5] == "DB") {
        select_subject.push_back(Subject::DB);
    }

    Date birth = get_date(temp[3]);
    Teacher teacher(temp[0], temp[1], birth, temp[3], temp[4], select_subject);
    return teacher;
}