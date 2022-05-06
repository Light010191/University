#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include"Student.h"
#include "Teacher.h"

//#include "deserialize.h"
using namespace std;

map<string, Teacher> teachers;
pair<string, Teacher>;
map<string, Student> students;
pair<string, Student>;

void welcome() {
    cout << "\t\t\t\t+--------------------+" << endl;
    cout << "\t\t\t\t| Univtrsity journal |" << endl;
    cout << "\t\t\t\t|        v0.1        |" << endl;
    cout << "\t\t\t\t+--------------------+" << endl;
}

void show_menu() {
    char number;
    cout << "\n\n---------------------------+" << endl;
    cout << "1. Show all                |" << endl;
    cout << "2. Show all teacher      |" << endl;
    cout << "3. Show all student      |" << endl;
    cout << "4. Add teacher             |" << endl;
    cout << "5. Add student             |" << endl;
    cout << "6. Add estimate            |" << endl;
    cout << "7. Output average estimates|" << endl;
    cout << "8. Save                    |" << endl;
    cout << "0. Exit                    |" << endl;
    cout << "---------------------------+" << endl;
    cin >> number;
    switch (number)
    {
    case '1':
        PrintTeacher(teachers);
        PrintStudent(students);
        break;
    case '2':
        PrintTeacher(teachers);
        break;
    case '3':
        PrintStudent(students);
        break;
    case '4':
        AddTeacher(teachers);
        break;
    case '5':
        AddStudent(students);
        break;
    case '6':
        AddEstimate(students);
        break;
    case '7':
        AverageEstimateStudent(students);
        break;
    case '8':

        break;
    default:
        break;
    }
}

void PrintTeacher(map<string, Teacher>& teachers) {
    for (pair<string, Teacher>item: teachers) { 
        cout << item.first << item.second.ToStringAll()<< item.second.GetSubject() << endl;        
    }
}

void PrintStudent(map<string, Student>& students) {
    for (pair<string, Student>item : students) {
        cout << item.first << item.second.ToStringAll() << endl;
    }
}

void AverageEstimateStudent(map<string, Student>& students) {
    string last_name;
    char select;
    Subject select_subject;
    cout << Subject::Programming << "Programming" << endl;
    cout << Subject::UI << "UI" << endl;
    cout << Subject::DB << "DB" << endl;
    cout << "Enter last name student" << endl;
    cin >> last_name;
    cout << "Enter subject: ";
    cin >> select;
    switch (select) {
    case '1':
        select_subject = Subject::Programming;
        break;
    case '2':
        select_subject = Subject::UI;
        break;
    case '3':
        select_subject = Subject::DB;
        break;
    }
    cout << students[last_name].GetAverageEstimate(select_subject);
}

void AddEstimate(map<string, Student>& students) {

    string last_name, subject;
    Subject subj;
    int estimate;
    char select;

    cout << "Enter last name student" << endl;
    cin >> last_name;
    cout << "Enter subject" << endl;
    cin >> subject;
    cout << "Enter estimate" << endl;
    cin >> estimate;
    cout << Subject::Programming << "Programming" << endl;
    cout << Subject::UI << "UI" << endl;
    cout << Subject::DB << "DB" << endl;
    cout << "If do you want close enter: Y " << endl;
    cout << "Enter subject: ";
    cin >> select;
    switch (select) {
    case '1':
        students[last_name].AddEstimate(Subject::Programming, estimate);
        break;
    case '2':
        students[last_name].AddEstimate(Subject::UI, estimate);
        break;
    case '3':
        students[last_name].AddEstimate(Subject::DB, estimate);
        break;
    }
    
}

void AddStudent(map<string, Student>& students) {

    char exit;
    string first_name, last_name, email, tel;
    int dd, mm, yyyy;
    Person info;
    Date date_info;

    do {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // пропускаем все до символа новой строки
        cout << "Enter first name" << endl;
        cin >> first_name;
        cout << "Enter last name" << endl;
        cin >> last_name;
        cout << "Enter email" << endl;
        cin >> email;
        cout << "Enter phone" << endl;
        cin >> tel;
        cout << "Enter date of birth (dd.mm.yyyy)" << endl;
        cin >> dd;
        cout << ".";
        cin >> mm;
        cout << ".";
        cin >> yyyy;
        cout << ".";
        cout << endl;

        cout << Faculty::Design << "Design" << endl;
        cout << Faculty::SoftDev << "SoftDev" << endl;
        cout << "Enter subject: ";
        Faculty select_subject;
        char select;
        cin >> select;
        switch (select) {
        case '1':
            select_subject = Faculty::Design;
            break;
        case '2':
            select_subject = Faculty::SoftDev;
            break;
        }

        date_info = { dd,mm,yyyy };
        info = { first_name, last_name, date_info, email, tel };
        Student student_info = { info, select_subject };
        students.insert(pair<string, Student>(last_name, student_info));

        cout << "If do you want close enter: Y " << endl;
        cin >> exit;
    } while (exit != 'Y' && exit != 'y');
}

void AddTeacher(map<string, Teacher>& teachers) {

    char exit;
    string first_name, last_name, email, tel;
    int dd, mm, yyyy;
    Person info;
    Date date_info;

    do {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // пропускаем все до символа новой строки
        cout << "Enter first name" << endl;
        cin >> first_name;
        cout << "Enter last name" << endl;
        cin >> last_name;
        cout << "Enter email" << endl;
        cin >> email;
        cout << "Enter phone" << endl;
        cin >> tel;
        cout << "Enter date of birth (dd.mm.yyyy)" << endl;
        cin >> dd;
        cout << ".";
        cin >> mm;
        cout << ".";
        cin >> yyyy;
        cout << ".";
        cout << endl;

        char select,exit1;
        Subjects select_subject;

        do {        
        cout << Subject::Programming << "Programming" << endl;
        cout << Subject::UI << "UI" << endl;
        cout << Subject::DB << "DB" << endl;
        cout << "If do you want close enter: Y " << endl;
        cout << "Enter subject: ";
        cin >> select;
        switch (select) {
        case '1':
            select_subject.push_back(Subject::Programming);
            break;
        case '2':
            select_subject.push_back(Subject::UI);
            break;
        case '3':
            select_subject.push_back(Subject::DB);
            break;
        }    
        cout << "If do you want close enter: Y " << endl;
        cin >> exit1;
        } while (exit1 != 'Y' && exit != 'y');

        date_info = { dd,mm,yyyy };
        info = { first_name, last_name, date_info, email, tel };
        Teacher teacher_info = { info, select_subject };
        teachers.insert(pair<string, Teacher>(last_name, teacher_info));

        cout << "If do you want close enter: Y " << endl;
        cin >> exit;
    } while (exit != 'Y' && exit != 'y');
}


vector<string> Parse(string str, string delimiter) {
    int pos = 0;
    string token;
    vector<string> temp;

    while ((pos = str.find(delimiter)) != string::npos) {
        token = str.substr(0, pos);
        temp.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    temp.push_back(str);

    return temp;
}
