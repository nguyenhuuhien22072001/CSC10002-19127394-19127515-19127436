#include "Manager.h"
//Chuc nang 36. xem ket qua diem danh
void View_check_in_result()
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

    string ID;
    cout << " Enter ID of student: ";
    getline(cin, ID);

    for (int i = 0; i < numofstudent; i++)
    {
        if (ID == student[i].id)
        {
            cout << "Buoi 1\tBuoi 2\tBuoi 3\tBuoi 4\tBuoi 5\tBuoi 6\tBuoi 7\tBuoi 8\tBuoi 9\tBuoi 10" << endl;
            for (int j = 0; j < 10; j++)
                cout << student[i].check_in[j] << "\t";
            cout << endl;
            return;
        }
    }
    cout << "Invalid ID !!!";
    return;
}