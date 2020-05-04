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
    string Class ; 
    Date dob;
    int male;//1:male,0:female
    string  degree; 
    string Class;
    int type; // 0: staff; 1: lecturer; 2: student
    int active;// 0:unactive; 1:active
};
void  first_menu();
void is_log_out();
void show_menu_staff() ; 
void show_menu_lecturer();
void show_menu_student();
void showInfo(Information person);
int login(fstream& fstu, fstream& fsta, fstream& flec);


//staff function
void Importstudent(ofstream& fstu, char* filename);
void load_file(fstream &fin ,const char* filename, int &n , Information* &Person);
void add_a_element_in_file(fstream &fout , const char* filename ,  int n , Information* &Person , Information person);
void manually_add_a_new_student_to_a_class(fstream &fstu, fstream &apcs1 , fstream &apcs2 , fstream &clc1 , fstream &clc2 , fstream &clc3 , fstream &clc4 , fstream &clc5 , fstream &clc6 ,  fstream &clc7 , fstream &clc8 , fstream &clc9 , fstream &clc10);
void add_element_into_file_student (Information person , fstream &fout);
void add_element_into_file_class (Information person , fstream &fout);
void add_student_into_file_student_and_flie_class( int n ,fstream &fstu , Information person , fstream &apcs1 , fstream &apcs2 , fstream &clc1 , fstream &clc2 , fstream &clc3 , fstream &clc4 , fstream &clc5 ,fstream &clc6 , fstream &clc7 , fstream &clc8 , fstream &clc9 , fstream &clc10);
void remove_a_element_in_file(fstream  &fout , const char* filename , int n , Information* &Person , Information person);
void remove_element_into_file_student(Information person , fstream &fout);
void remove_element_into_file_class (Information person , fstream &fout);
void remove_student_in_file_student_and_flie_class( int n ,fstream &fstu , Information person , fstream &apcs1 , fstream &apcs2 , fstream &clc1 , fstream &clc2 , fstream &clc3 , fstream &clc4 , fstream &clc5 ,fstream &clc6 ,  fstream &clc7 , fstream &clc8 , fstream &clc9 , fstream &clc10);
void remove_a_student(fstream &fstu , fstream &apcs1 , fstream &apcs2 , fstream &clc1 , fstream &clc2 , fstream &clc3 , fstream &clc4 , fstream &clc5 ,fstream &clc6 ,  fstream &clc7 , fstream &clc8 , fstream &clc9 , fstream &clc10);
#endif