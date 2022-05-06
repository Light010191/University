#pragma once

#include <fstream>
#include <map>

#include "Date.h"
#include "cli.h"
#include "deserialize.h"

using namespace std;


void save(map<string, Student> students, map<string, Teacher> teachers) {
    ofstream file;
    file.open("tasks.dsv");

    if (file.is_open()) {
        for (pair<string, Teacher>item : teachers) {            
            file << item.first << item.second.ToStringAll() << item.second.GetSubject() << endl;
        }
        for (pair<string, Student>item : students) {
            file << item.first << item.second.ToStringAll() << endl;
        }
    }

    file.close();
}

void importAll(map<string, Student> students, map<string, Teacher> teachers) {

    string line;
    ifstream file;
    file.open("tasks.dsv");

    if (file.is_open()) {
        while (file >> line)
        {
            auto temp = Parse(line, "|");
            string title = temp[0];
            students.insert(pair<string, Student>(title, (get_student(line))));
            teachers.insert(pair<string, Teacher>(title, (get_teacher(line))));
        }
    }
    file.close();
}

