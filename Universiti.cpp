#include <iostream>

#include "Student.h"
#include "Teacher.h"
#include "Subject.h"
#include "Faculty.h"
#include"cli.h"
#include"file_utilites.h"

using namespace std;


int main() {

    importAll(students,teachers);

    welcome();
    show_menu();  

    save(students, teachers);

    return 0;
}