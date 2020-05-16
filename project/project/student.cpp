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
//Chuc nang 37. xem thoi khoa bieu
void View_schedule()
{
    string academic_year, semester, classname;
    int numofcourses;
    course* Courses = NULL;

    cout << "Enter academic year: ";
    getline(cin, academic_year);

    cout << "Enter semesster :";
    getline(cin, semester);

    cout << "Enter classname: ";
    getline(cin, classname);

    loadCourses(academic_year, semester, classname, Courses, numofcourses);
    cout << "ID  name of Course  name of Lecture  Start date  End date  Start Hour  End Hour  Day  Room" << endl;
    for (int i = 0; i < numofcourses; i++)
    {
        cout << Courses[i].ID << "  " << Courses[i].name << "  ";
        cout << Courses[i].lecture.fullname << "  ";
        cout << Courses[i].startD.date << "/" << Courses[i].startD.month << "/" << Courses[i].startD.year << "  ";
        cout << Courses[i].endD.date << "/" << Courses[i].endD.month << "/" << Courses[i].endD.year << "  ";
        cout << Courses[i].startH.hour << " : " << Courses[i].startH.minute << "  ";
        cout << Courses[i].endH.hour << " : " << Courses[i].endH.minute << "  ";
        cout << Courses[i].dayofweek << "  ";
        cout << Courses[i].room << endl;
    }
}
//Chuc nang 38: Xem bang diem cua sinh vien
void View_score_board_myseft()
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
            cout << "Lab\tMidterm\tFinal\tBonus" << endl;
            cout << student[i].mark.lab << "\t" << student[i].mark.midterm << "\t" << student[i].mark.final << "\t" << student[i].mark.bonus;
            cout << endl;
            return;
        }
    }
    cout << "Invalid ID !!!";
    return;
}