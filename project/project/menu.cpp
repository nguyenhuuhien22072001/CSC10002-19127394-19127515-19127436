#include "Manager.h"
void  first_menu()
{
   int n ;  
   cout << "0 - Log out" << endl ; 
   cout << "1 - Log in " << endl ; 
   cout << " You option :" << endl ;
   cin >> n  ; 
   if (n == 0)
       exit ;
}
void is_log_out()
{
    int n ; 
    cout << "0 - Log out" << endl ; 
    cout << "1 - Continue " << endl ; 
    cout << " You option :" << endl ;
    cin >> n ; 
    if (n == 0)
       exit ;
}
void show_menu_staff() {
    int n;
    cout << "0 - Import students of a class. " << endl;
    cout << "1 - Add a new student to a class. " << endl;
    cout << "2 - Edit an existing student. " << endl;
    cout << "3 - Remove a student. " << endl;
    cout << "4 - Change students from a class A to class B. " << endl;
    cout << "5 - View list of classes. " << endl;
    cout << "6 - View list of students in a class. " << endl;
    cout << "7 - Create / View academic years and semester." << endl;
    cout << "8 - Import courses from a semester." << endl;
    cout << "9 - Add a new course." << endl;
    cout << "10 - Edit an existing course. " << endl;
    cout << "11 - Remove a course." << endl;
    cout << "12 - Remove a specific student from a course." << endl;
    cout << "13 - Add a specific student to a course." << endl;
    cout << "14 - View list of courses in the current semester. " << endl;
    cout << "15 - View list of students of a course." << endl;
    cout << "16 - View attendance list of a course. " << endl;
    cout << "17 - Create / View all lecturers." << endl;
}