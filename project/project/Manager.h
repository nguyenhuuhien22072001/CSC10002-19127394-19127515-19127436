#ifndef _MANAGER_H_
#define _MANAGER_H_
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
using namespace std;
struct Date {
    int date, month, year;
};
struct Information {
    string id;
    string password;
    string fullname;
    Date dob;
    string  degree; 
    int type; // 0: staff; 1: lecturer; 2: student
};
#endif
