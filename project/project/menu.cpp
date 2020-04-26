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
void show_menu_lecturer()
{
    cout << "0 - View list of courses in the current semester."<< endl ;
    cout << "1 - View list of students of a course." << endl ; 
    cout << "2 - View attendance list of a course." << endl ; 
    cout << "3 - Edit an attendance." << endl ; 
    cout << "4 - Import scoreboard of a course (midterm, final, lab) from a csv file." << endl ; 
    cout << "5 - Edit grade of a student." << endl ; 
    cout << "6 - View a scoreboard." << endl ; 
}
void show_menu_student()
{
    cout << "Check-in." << endl ; 
    cout << "View check-in result." << endl ; 
    cout << "View schedules."  << endl ;
    cout << "View his/her scores of a course." << endl ;
}
