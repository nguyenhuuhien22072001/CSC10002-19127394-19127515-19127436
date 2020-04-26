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