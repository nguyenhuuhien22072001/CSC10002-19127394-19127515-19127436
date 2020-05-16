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
            {
                cout << "Buoi " << j + 1 << ": ";
                cin >> student[i].check_in[j];
            }
        }
    saveStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
}
//Chuc nang 32
void load_score_board()
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

    char inputpath[101];
    cout << "Enter csv file name: ";
    cin.getline(inputpath, 101);
    ifstream fin;

    fin.open(inputpath);
    if (!fin.is_open())
    {
        cout << "Fail" << endl;
        return;
    }
    string s;
    getline(fin, s);
    for (int i = 0; i < numofstudent; i++)
    {
        char c;
        string s1;
        getline(fin, s1, ',');
        getline(fin, s1, ',');
        fin >> student[i].mark.lab;
        fin >> c;
        fin >> student[i].mark.midterm;
        fin >> c;
        fin >> student[i].mark.final;
        fin >> c;
        fin >> student[i].mark.bonus;
        fin >> c;
    }

    saveStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
}
//Chuc nang 33
void Edit_grade_of_a_student()
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

    bool check=false;
    for (int i = 0; i < numofstudent; i++)
    {
        if (ID == student[i].id)
        {
            check = true;
            cout << "Enter lab mark: ";
            cin >> student[i].mark.lab;
            cout << "Enter midterm mark: ";
            cin >> student[i].mark.midterm;
            cout << "Enter final mark: ";
            cin >> student[i].mark.final;
            cout << "Enter bonus mark: ";
            cin >> student[i].mark.bonus;
        }
    }
    if (check == true)
    {
        saveStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
        return;
    }
    else
    {
        cout << " Invalid ID !!";
        return;
    }
}
