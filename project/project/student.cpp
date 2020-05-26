#include "Manager.h"
// Chức năng 35 : Check in
const string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    localtime_s(&tstruct, &now);
    strftime(buf, sizeof(buf), "%Y %m %d %X", &tstruct);

    return buf;
}
void check_in(student_in_course &student)
{
    cin.ignore();
    string academic_year ; string semester ; string classname ; string courseName;
    cout << "Enter academic year : " ;
    getline(cin , academic_year) ;
    cout << "Enter semester : " ;
    getline(cin , semester) ;
    cout << "Enter classname: " ; 
    getline(cin , classname) ; 
    cout << "Enter courseName: " ;
    getline(cin , courseName) ;
    student_in_course * Student ;
    int numofStudent = 0 ;
    loadStudentOfACourse(academic_year, semester,classname, courseName, Student, numofStudent);
    const string time_now = currentDateTime() ;
    rsize_t strmax = sizeof((char*)time_now.c_str());
    int num[6] ;
    char *p;
    int index = 0;
    char* p_ch = strtok_s((char*)time_now.c_str(), ": ", &p);

    while(p_ch != NULL)
    {
            num[index] = atoi(p_ch) ;
            index++;
            p_ch=strtok_s(NULL, ": ",&p);
    }
    for(int i = 0 ; i < numofStudent ; i++)
    {
        if(Student[i].id == student.id)
        {
            for(int j = 0 ; j < 10 ;  j++)
            {
                int StartTime = Student[i].StartTime[j].hour*60 + Student[i].StartTime[j].minute ;
                
                int EndTime = Student[i].EndTime[j].hour*60 + Student[i].EndTime[j].minute ;
                if( Student[i].date[j].year == num[0] &&  Student[i].date[j].month == num[1] && Student[i].date[j].date == num[2] &&
                    StartTime <= (num[3]*60 + num[4]) &&
                    (num[3]*60 + num[4]) <= EndTime)
                {
                    Student[i].check_in[j] = 1 ;
                    cout << "Check-in successfully" << endl ;
                    cout << num[0] << "-" << num[1] << "-" << num[2] << " " << Student[i].StartTime[j].hour <<":" << Student[i].StartTime[j].minute << " " << Student[i].EndTime[j].hour << ":" <<Student[i].EndTime[j].minute << " " << Student[i].check_in[j] << endl ;
                }
            }
            saveStudentOfACourse(academic_year, semester, classname, courseName, Student, numofStudent);
            delete[] Student;
            return;
        }
    }
    cout << "Check-in failed !!!" << endl;
    return;
}
//Chuc nang 36. xem ket qua diem danh
void print_check_in(int a)
{
    if(a < 10)
        cout <<"0"<< a << " " ;
    else
        cout << a << " " ;
}

void View_check_in_result(student_in_course student)
{
    cin.ignore();
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter classname" ; 
    getline(cin , classname) ; 
    cout << "Enter course name: ";
    getline(cin, coursename);

    student_in_course* Student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, Student, numofstudent);

    for (int i = 0; i < numofstudent; i++)
    {
        if (student.id == Student[i].id)
        {
            for (int j = 0; j < 10; j++)
            {
                print_check_in(Student[i].date[j].year);
                print_check_in(Student[i].date[j].month);
                print_check_in(Student[i].date[j].date);
                print_check_in(Student[i].StartTime[j].hour);
                print_check_in(Student[i].StartTime[j].minute);
                print_check_in(Student[i].EndTime[j].hour);
                print_check_in(Student[i].EndTime[j].minute);
                if(Student[i].check_in[j] == -1)
                    cout << "NO" << endl ;
                else
                    cout << "YES" << endl ;
            }
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