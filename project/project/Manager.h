#ifndef _MANAGER_H_
#define _MANAGER_H_
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Date {
    int date, month, year;
};
struct Information {
    string id;
    string password;
    string fullname;
    Date dob;
    int type; // 0: staff; 1: lecturer; 2: student
};
#endif
