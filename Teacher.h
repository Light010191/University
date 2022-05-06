#pragma once
#include <string>
#include <vector>

#include "Person.h"
#include "Subject.h"

using namespace std;

using Subjects = vector<Subject>;

class Teacher : public Person {
protected:
    Subjects subjects;

public:
    Teacher() {}
    Teacher(string first_name, string last_name, Date date_of_birth, string email,
        string tel, Subjects subjects) : Person(first_name, last_name, date_of_birth, email, tel),
        subjects(subjects) {}
    Teacher(Person person, Subjects subjects) : Person(person), subjects(subjects) {}

     string GetSubject() {
        for (auto i :subjects) {
            cout << subjects[i];
            return to_string(subjects[i]);
        }        
     }
};