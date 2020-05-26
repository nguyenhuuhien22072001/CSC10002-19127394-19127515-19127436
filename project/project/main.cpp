#include "Manager.h"

int main()
{
	first_menu();
    cin.ignore();
	Information person ; 
	fstream fstu, fsta, flec; 
    /*fstu.open("D:\\filetest\\Student.txt",ios::in);
    fsta.open("D:\\filetest\\Staff.txt",ios::in);
    flec.open("D:\\filetest\\Lecture.txt",ios::in);*/
	int num = login(fstu, fsta, flec,person);
	while(num == -1)
    {
        cout << "log in fail , try again ." << endl ;
        num = login(fstu, fsta, flec,person);
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
                                    createSemester();
                                    break ;
                                }
                                case  8 :
                                {
                                    ImportCourses();
                                    break ;
                                }
                                case 9 :
                                {
                                    Add_Course();
                                    break ;
                                }
                                case 10 :
                                {
                                    Edit_a_course();
                                    break ;
                                }
                                case 11 :
                                {
                                    Remove_course();
                                    break ;
                                }
                                case 12 :
                                {
                                     Remove_student_from_a_course();
                                    break ;
                                }
                                case 13 :
                                {
                                    Add_student_into_course();
                                    break ;
                                }
                                case 14 :
                                {
                                    View_list_courses();
                                    break ;
                                }
                                case 15 :
                                {
                                    View_list_students_of_course();
                                    break ;
                                }
                                case 16 :
                                {
                                    View_attendance_list();
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
                        showInfo_staff(person) ;
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
                    int num3 ; 
                    cout << "You option : " ; 
                    cin >> num3 ;
                    while(num3 != -1)
                    {
                        switch(num3)
                        {
                            case 0 : 
                            {
                                View_list_courses();
                                break ; 
                            }
                            case 1 : 
                            {
                                View_list_students_of_course();
                                break ; 
                            }
                            case 2 : 
                            {
                                View_attendance_list();
                                break ; 
                            }
                            case 3 : 
                            {
                                Edit_an_attendance();
                                break ; 
                            }
                            case 4 : 
                            {
                                load_score_board();
                                break ; 
                            }
                            case 5 : 
                            {
                                Edit_grade_of_a_student();
                                break ; 
                            }
                            case 6 : 
                            {
                                View_scoreboard_course();
                                break ; 
                            }
                            default : 
                                break ; 
                        }
                        cout << "You option : " ; 
                        cin >> num3 ;
                    }
                    break ;
                case 2 :
                    showInfo_lecturer(person) ;
                    break ;
                case 3 :
                    change_password(person);
            }
        }
        else
        {
            student_in_course student ;
            student.id = person.id ;
            switch(num2)
            {
                case 1 :
                    show_menu_student();
                    int num3 ; 
                    cout << "You option : "; 
                    cin >> num3 ;
                    while(num3 != -1)
                    {
                        switch(num3)
                        {
                            case 0 : 
                            {
                                check_in(student);
                                break;
                            }
                            case 1 : 
                            {
                                View_check_in_result(student);
                                break;
                            }
                            case 2 : 
                            {
                                View_schedule();

                                break;
                            }
                            case 3 : 
                            {
                                View_score_board_myseft();
                                break;
                            }
                            default:
                                break ;
                        }
                        cout << "You option : " ; 
                        cin >> num3 ;
                    }
                    break ;
                case 2 :
                    showInfo_student(person) ;
                    break ;
                case 3 :
                    change_password(person);
            }
        }
        cout << "You option : " ;
        cin >> num2 ;
    }
//ImportCourses();
//cout << "ADD course: " << endl;
//Add_Course();
//Remove_course();
//Remove_student_from_a_course();
//Add_student_into_course();
//View_list_courses();
//View_list_students_of_course();
//View_scoreboard_course();
//save_scoreboard();
//View_attendance_list();
//save_attendance_list();
//Edit_an_attendance();
//Edit_grade_of_a_student();
//View_check_in_result();
//View_schedule();
//View_score_board_myseft();
return 0;

}