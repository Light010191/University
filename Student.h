#pragma once
#include <string>
#include <map>
#include <vector>

#include "Person.h"
#include "Subject.h"
#include "Faculty.h"

using namespace std;

using Estimates = map<Subject, vector<int>>;
using EstimatesItem = pair<Subject, vector<int>>;

class Student : public Person {
protected:
    Faculty faculty;
    Estimates estimates;

public:
    Student() {};
    Student(string first_name, string last_name, Date date_of_birth, string email,
        string tel, Faculty faculty) : Person(first_name, last_name, date_of_birth, email, tel),
        faculty(faculty) {}

    Student(Person person, Faculty faculty) : Person(person), faculty(faculty) {}

    double GetAverageEstimate(Subject subject) {
        auto list_estimates = estimates[subject];

        int sum = 0;
        for (auto estimate : list_estimates) {
            sum += estimate;
        }

        return (double)sum / list_estimates.size();
    }
    void AddEstimate(Subject subject, int estimate) {
        auto is_contains = estimates.find(subject);
        if (is_contains != estimates.end()) {
            estimates[subject].push_back(estimate);
        }
        else {
            vector<int> temp;
            temp.push_back(estimate);
            estimates.insert(EstimatesItem(subject, temp));
        }
    }   
};