#include "Manager.h"

int main()
{
	first_menu();
	Information person ; 
	fstream fstu, fsta, flec; 
	int num=login(fstu, fsta, flec);
	if(num == -1)
	{
		cout << "Log in fail , try again" << endl ; 
		//return login(fstu, fsta, flec);
	}
	else
	{
		int num2 ; 
		cout << "1 - Show menu" << endl ; 
		cout << "2 - View Profile" << endl ;
		cout << "3 - Change password" << endl ; 
		cout << "4 - Log out" << endl ; 
		cout << "You option : " ; 
		while(num2 != 4)
		{
			switch (num2)
			{
				case 1:
				{
					if (num == 0)
					{
						int choice;
						show_menu_staff();
						cout << "Choose option: ";
						cin >> choice;
					}
					else if (num == 1)
					{
						int choice;
						show_menu_lecturer();
						cout << "Choose option: ";
						cin >> choice;
					}
					else
					{
						int choice;
						show_menu_student;
						cout << "Choose option: ";
						cin >> choice;
					}
					break;
				}
				case 2 : 
					showInfo(person);
					break;
				case 3 : 
					break ; 
				default:
					break;
			}
		}
	}

	
	return 0;
}