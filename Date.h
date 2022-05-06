#pragma once

#include <string>

using namespace std;

struct Date {
    int year;
    int month;
    int day;

    Date() {}
    Date(int year, int month, int day) {
        this->year = year;
        this->month = month;
        this->day = day;
    }

    string to_string() { // dd.mm.yyyy
        return ::to_string(day) + "." + ::to_string(month) + "." + ::to_string(year);
    }
};