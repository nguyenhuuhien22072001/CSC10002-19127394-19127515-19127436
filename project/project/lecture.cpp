#include "Manager.h"
//---------------------------------------------LECTURE--------------------------------------
//Chuc nag 29
void View_list_students_of_course_lecture(Information lecture)
{
    course* Courses = NULL;
    int num_of_courses;
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    loadCourses(academic_year, semester, classname, Courses, num_of_courses);

    cout << "Enter course name: ";
    getline(cin, coursename);
    bool check = false;
    for (int i = 0; i < num_of_courses; i++)
    {
        if (Courses[i].lecture.id == lecture.id && Courses[i].name == coursename)
            check = true;
    }
    if (check == false)
    {
        cout << " This class is not yours" << endl;
        return;
    }

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
    cout << "List of students in course " << coursename << " :" << endl;
    for (int i = 0; i < numofstudent; i++)
        cout << student[i].id << "." << student[i].fullname << endl;
    delete[]Courses;
    delete[]student;
}
//Chuc nang 30
void View_attendance_list_of_course(Information lecture)
{
    course* Courses = NULL;
    int num_of_courses;
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    loadCourses(academic_year, semester, classname, Courses, num_of_courses);

    cout << "Enter course name: ";
    getline(cin, coursename);
    bool check = false;
    for (int i = 0; i < num_of_courses; i++)
    {
        if (Courses[i].lecture.id == lecture.id && Courses[i].name == coursename)
            check = true;
    }
    if (check == false)
    {
        cout << " This class is not yours" << endl;
        return;
    }

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
    cout << "Attendance list of course " << coursename << " :" << endl;
    cout << "ID\t\tFull name\tBuoi 1\tBuoi 2\tBuoi 3\tBuoi 4\tBuoi 5\tBuoi 6\tBuoi 7\tBuoi 8\tBuoi 9\tBuoi 10" << endl;
    for (int i = 0; i < numofstudent; i++)
    {
        cout << student[i].id << "\t\t" << student[i].fullname << "\t";
        for (int j = 0; j < 10; j++)
            cout << student[i].check_in[j] << "\t";
        cout << endl;
    }
    delete[]Courses;
    delete[]student;
}
//Chuc nang 31
void Edit_an_attendance(Information lecture)
{
    course* Courses = NULL;
    int num_of_courses;
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    loadCourses(academic_year, semester, classname, Courses, num_of_courses);

    cout << "Enter course name: ";
    getline(cin, coursename);
    bool check = false;
    for (int i = 0; i < num_of_courses; i++)
    {
        if (Courses[i].lecture.id == lecture.id && Courses[i].name == coursename)
            check = true;
     }
    if (check == false)
    {
        cout << " This class is not yours" << endl;
        return;
    }
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
    delete[]Courses;
    delete[]student;
}
//Chuc nang 32
void load_score_board(Information lecture)
{
    course* Courses = NULL;
    int num_of_courses;
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    loadCourses(academic_year, semester, classname, Courses, num_of_courses);

    cout << "Enter course name: ";
    getline(cin, coursename);
    bool check = false;
    for (int i = 0; i < num_of_courses; i++)
    {
        if (Courses[i].lecture.id == lecture.id && Courses[i].name == coursename)
            check = true;
    }
    if (check == false)
    {
        cout << " This class is not yours" << endl;
        return;
    }

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

    delete[]Courses;
    delete[]student;
}
//Chuc nang 33
void Edit_grade_of_a_student(Information lecture)
{
    course* Courses = NULL;
    int num_of_courses;
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    loadCourses(academic_year, semester, classname, Courses, num_of_courses);

    cout << "Enter course name: ";
    getline(cin, coursename);
    bool check = false;
    for (int i = 0; i < num_of_courses; i++)
    {
        if (Courses[i].lecture.id == lecture.id && Courses[i].name == coursename)
            check = true;
    }
    if (check == false)
    {
        cout << " This class is not yours";
        return;
    }

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);

    string ID;
    cout << " Enter ID of student: " << endl;
    getline(cin, ID);

    check=false;
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
    delete[]Courses;
    delete[]student;
}
//Chuc nang 34
void View_scoreboard_course_lecture(Information lecture)
{
    course* Courses = NULL;
    int num_of_courses;
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    loadCourses(academic_year, semester, classname, Courses, num_of_courses);

    cout << "Enter course name: ";
    getline(cin, coursename);
    bool check = false;
    for (int i = 0; i < num_of_courses; i++)
    {
        if (Courses[i].lecture.id == lecture.id && Courses[i].name == coursename)
            check = true;
    }
    if (check == false)
    {
        cout << " This class is not yours" << endl;
        return;
    }

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
    cout << "Scoreboard of course " << coursename << " :" << endl;
    cout << "ID\t\tFull name\tLab\tMidterm\tFinal\tBonus" << endl;
    for (int i = 0; i < numofstudent; i++)
    {
        cout << student[i].id << "\t\t" << student[i].fullname << "\t";
        cout << student[i].mark.lab << "\t" << student[i].mark.midterm << "\t" << student[i].mark.final << "\t" << student[i].mark.bonus << endl;
    }
    delete[]Courses;
    delete[]student;
}
