#include "Manager.h"
void manually_add_a_new_student_to_a_class(fstream &fstu , Information person)
{   
    cout << "Enter class : " ; 
    getline(cin , person.Class); 
    cout << "Enter ID : "; 
    getline(cin , person.id); 
    cout << "Enter fullname : ";
    getline(cin , person.fullname); 
    cout << "Enter Year of birth : " ; 
    cin >> person.dob.year ; 
    cout << "Enter month" ; 

    // cout << "0 - 19APCS1" << endl ; 
    // cout << "1 - 19APCS2" << endl ; 
    // cout << "2 - 19CLC1" << endl ;
    // cout << "3 - 19CLC2" << endl ;
    // cout << "4 - 19CLC3" << endl ;
    // cout << "5 - 19CLC4" << endl ;
    // cout << "6 - 19CLC5" << endl ;
    // cout << "7 - 19CLC6" << endl ;
    // cout << "8 - 19CLC7" << endl ;
    // cout << "9 - 19CLC8" << endl ;
    // cout << "10 - 19CLC9" << endl ;
    // cout << "11 - 19CLC10" << endl ;
    // cout << "You option : " ; 
    // cin >> n 


}