#include "Manager.h"
//---------------------------------------------LECTURE--------------------------------------
//Chuc nang 31
void Edit_an_attendance()
{
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    cout << "Enter course name: ";
    getline(cin, coursename);

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);

    string id, fullname;
    cout << "Enter id: ";
    getline(cin, id);
    cout << "Enter full name: ";
    getline(cin, fullname);
    for (int i = 0; i < numofstudent; i++)
        if (id == student[i].id)
        {
            cout << "Enter attendance list of student(1.attendance, 0.absent) " << student[i].fullname << " : ";
            for (int j = 0; j < 10; j++)
                cin >> student[i].check_in[j];
        }
    saveStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
}