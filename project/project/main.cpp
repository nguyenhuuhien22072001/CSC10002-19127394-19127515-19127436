#include "Manager.h"

int main()
{
	/*first_menu();
	Information person ; 
	fstream fstu, fsta, flec; 
	int num = login(fstu, fsta, flec);
	while(num == -1)
{
    cout << "log in fail , try again ." << endl ;
    num = login(fstu, fsta, flec);
}
    int num2 ;
    cout << "1 - Show menu" << endl ;
    cout << "2 - View Profile" << endl ;
    cout << "3 - Change password" << endl ;
    cout << "4 - Log out" << endl ;
    cout << "You option : " ;
    cin  >> num2 ;
    while(num2 != 4)
    {
        if (num == 0)
        {
            switch(num2)
                {
                    case 1 :
                    {
                        show_menu_staff();
                        int num3 ;
                        cout << "You option : ";
                        cin >> num3 ;
                        while(num3 != -1)
                        {
                            switch(num3)
                            {
                                case 0 :
                                {
                                    Importstudents();
                                    break ;
                                }
                                case 1 :
                                {
                                    manually_add_a_new_student_to_a_class();
                                    break ;
                                }
                                case 2 :
                                {
                                    edit_student();
                                    break ;
                                }
                                case 3 :
                                {
                                    remove_a_student();
                                    break ;
                                }
                                case 4 :
                                {
                                    break ;
                                }
                                case 5 :
                                {
                                    break ;
                                }
                                case 6 :
                                {
                                    break ;
                                }
                                case 7 :
                                {
                                    break ;
                                }
                                case  8 :
                                {
                                    break ;
                                }
                                case 9 :
                                {
                                    break ;
                                }
                                case 10 :
                                {
                                    break ;
                                }
                                case 11 :
                                {
                                    break ;
                                }
                                case 12 :
                                {
                                    break ;
                                }
                                case 13 :
                                {
                                    break ;
                                }
                                case 14 :
                                {
                                    break ;
                                }
                                case 15 :
                                {
                                    break ;
                                }
                                case 16 :
                                {
                                    break ;
                                }
                                case 17 :
                                {
                                    break ;
                                }
                                default :
                                    break ;
                            }
                        }
                    }
                    case 2 :
                        showInfo(person) ;
                        break ;
                    case 3 :
                        change_password(person);
                        break ;
                    default :
                        break ;
                }
        }
        else if (num == 1)
        {
            switch(num2)
            {
                case 1 :
                    show_menu_lecturer();
                    break ;
                case 2 :
                    showInfo(person) ;
                    break ;
                case 3 :
                    change_password(person);
            }
        }
        else
        {
            switch(num2)
            {
                case 1 :
                    show_menu_student();
                    break ;
                case 2 :
                    showInfo(person) ;
                    break ;
                case 3 :
                    change_password(person);
            }
        }
        cout << "You option : " ;
        cin >> num2 ;
    }*/
ImportCourses();
//cout << "ADD course: " << endl;
//Add_Course();
//Remove_course();
Remove_student_from_a_course();
return 0;

}