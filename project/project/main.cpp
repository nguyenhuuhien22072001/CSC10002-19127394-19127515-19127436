#include "Manager.h"

int main()
{
    int n;
    cout << "0 - Log out" << endl;
    cout << "Press any number - Log in " << endl;
    cout << " You option :";
    cin >> n;
    if (n == 0)
        return 0;
    cin.ignore();
	Information person ; 
	fstream fstu, fsta, flec; 
	int type = login(fstu, fsta, flec,person);
    //cout << flush;
	while(type == -1)
    {
        cout << "log in fail , try again ." << endl ;
        system("pause");
        system("cls");
        first_menu();
        cin.ignore();
        type = login(fstu, fsta, flec,person);
    }
    int option_login ;
    cout << "1 - Show menu" << endl ;
    cout << "2 - View Profile" << endl ;
    cout << "3 - Change password" << endl ;
    cout << "4 - Log out" << endl ;
    cout << "You option : " ;
    cin  >> option_login;
    cin.ignore();
    cout << endl;
    while(option_login != 4)
    {
        if (type == 0)
        {
            switch(option_login)
                {
                    case 1 :
                    {
                        show_menu_staff();
                        int option_staff ;
                        cout << "You option : ";
                        cin >> option_staff;
                        cin.ignore();
                        cout << endl;
                        while(option_staff != -1)
                        {
                            switch(option_staff)
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
                                    change_student_to_another_class();
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
                                    View_scoreboard_course();
                                    break ;
                                }
                                case 17 :
                                {
                                    save_scoreboard();
                                    break ;
                                }
                                case 18:
                                {
                                    View_attendance_list();
                                    break;
                                }
                                case 19:
                                {
                                    save_attendance_list();
                                    break;
                                }
                                case 20:
                                {
                                    break;
                                }
                                default :
                                    break ;
                            }
                            system("pause");
                            system("cls");
                            show_menu_staff();
                            cout << "You option : ";
                            cin >> option_staff;
                            cin.ignore();
                            cout << endl;
                        }
                        break;
                    }
                    case 2 :
                    {
                        showInfo_staff(person);
                        break;
                    }
                    case 3 :
                    {
                        change_password(person);
                        break;
                    }
                    default :
                        break ;
                }
        }
        else if (type == 1)
        {
            switch(option_login)
            {
                case 1 :
                    show_menu_lecturer();
                    int option_lecture ; 
                    cout << "You option : " ; 
                    cin >> option_lecture;
                    cin.ignore();
                    cout << endl;
                    while(option_lecture != -1)
                    {
                        switch(option_lecture)
                        {
                            case 0 : 
                            {
                                View_list_courses();
                                break ; 
                            }
                            case 1 : 
                            {
                                View_list_students_of_course_lecture(person);
                                break ; 
                            }
                            case 2 : 
                            {
                                View_attendance_list_of_course(person);
                                break ; 
                            }
                            case 3 : 
                            {
                                Edit_an_attendance(person);
                                break ; 
                            }
                            case 4 : 
                            {
                                load_score_board(person);
                                break ; 
                            }
                            case 5 : 
                            {
                                Edit_grade_of_a_student(person);
                                break ; 
                            }
                            case 6 : 
                            {
                                View_scoreboard_course_lecture(person);
                                break ; 
                            }
                            default : 
                                break ; 
                        }
                        system("pause");
                        system("cls");
                        show_menu_lecturer();
                        cout << "You option : ";
                        cin >> option_lecture;
                        cin.ignore();
                        cout << endl;
                    }
                    break ;
                case 2 :
                    showInfo_lecturer(person) ;
                    break ;
                case 3 :
                    change_password(person);
                    break;
                default:
                    break;
            }
        }
        else
        {
            student_in_course student ;
            student.id = person.id ;
            switch(option_login)
            {
                case 1 :
                    show_menu_student();
                    int option_student ; 
                    cout << "You option : "; 
                    cin >> option_student;
                    cin.ignore();
                    cout << endl;
                    while(option_student != -1)
                    {
                        switch(option_student)
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
                        system("pause");
                        system("cls");
                        show_menu_student();
                        cout << "You option : ";
                        cin >> option_student;
                        cin.ignore();
                    }
                    break ;
                case 2 :
                    showInfo_student(person) ;
                    break ;
                case 3 :
                    change_password(person);
                default:
                    break;
            }
        }
        system("pause");
        system("cls");
        cout << "1 - Show menu" << endl;
        cout << "2 - View Profile" << endl;
        cout << "3 - Change password" << endl;
        cout << "4 - Log out" << endl;
        cout << "You option : ";
        cin >> option_login;
        cin.ignore();
        cout << endl;
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