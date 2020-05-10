#ifndef _MANAGER_H_
#define _MANAGER_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;
struct Date {
    int  date, month, year;
};
struct Information {
    string id;
    string password;
    string fullname;
    Date dob;
    string Class;
    int active;// 0:unactive; 1:active
    int male;//1:male,0:female
    string  degree; 
    int type; // 0: staff; 1: lecturer; 2: student
};
struct time {
    int hour;
    int minute;
};
struct course {
    int no;
    string ID;
    string name;
    string classname;
    Information lecture;
    Date startD;
    Date endD;
    int dayofweek;
    time startH;
    time endH;
    string room;
};
void  first_menu();
void is_log_out();
void show_menu_staff() ; 
void show_menu_lecturer();
void show_menu_student();
void showInfo(Information person);
int login(fstream& fstu, fstream& fsta, fstream& flec);


//staff function
void loadStudent(Information*& student, string classname, int& n);
void saveStudent(Information* student, string classname, int n);
void Importstudents();
void saveStudent(Information* student, string classname, int n);
void edit_student();
void load_file( const char * filename , int &n ,  Information* &Person );
void add_a_element_in_file( const char * filename ,  int n , Information* &Person , Information person);
void add_student_into_file_student_and_flie_class(Information person);
void manually_add_a_new_student_to_a_class();
void remove_a_element_in_file(const char* filename , int n , Information* &Person , Information person);
void remove_student_in_file_student_and_flie_class(  Information person);
void remove_a_student();
void manually_add_a_new_student_to_a_class(fstream &fstu , Information person);

//----------------couses-------------------------------------------------------

//  13.
void createSemester();

//  14.
int sum_day(Date date);
int find_day_of_week(Date date);
int month2(Date date);
Date add_date(Date date, int numofday);
Date first_lesson(Date startD, int dayofweek);

void saveCourses(string academic_year, string semester, string classname, course* Courses, int numofcourse);
void saveStudentOfCourse(string academic_year, string semester, string classname, course* Courses,int numofcourse);
void ImportCourses();
#endif