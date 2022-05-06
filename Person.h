#pragma once
#include <string>

#include "Date.h"

using namespace std;

class Person {
protected:
    string first_name;
    string last_name;
    Date date_of_birth;
    string email;
    string tel;

public:
    Person() {}

    Person(string first_name, string last_name, Date date_of_birth, string email, string tel) : first_name(first_name),
        last_name(last_name),
        date_of_birth(
            date_of_birth),
        email(email),
        tel(tel) {}

    Person(Person const& person) {
        first_name = person.GetFirstName();
        last_name = person.GetLastName();
        date_of_birth = person.GetDateOfBirth();
        email = person.GetEmail();
        tel = person.GetTel();
    }

    string GetFirstName() const {
        return first_name;
    }

    string GetLastName() const {
        return last_name;
    }

    Date GetDateOfBirth() const {
        return date_of_birth;
    }

    string GetEmail() const {
        return email;
    }

    string GetTel() const {
        return tel;
    }

    string GetName() {
        return last_name + " " + first_name;
    }

    string ToStringAll() {
        return last_name + " " + first_name + " " + date_of_birth.to_string() + " " + email  +" " + tel;
    }
};