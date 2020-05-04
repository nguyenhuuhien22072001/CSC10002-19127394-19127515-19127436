#include "Manager.h"

int main()
{
	first_menu();
	fstream fstu, fsta, flec;
	fstream apcs1 , apcs2 , clc1 , clc2 , clc3 , clc4 , clc5 , clc6 , clc7 , clc8 ,clc9 , clc10 ;
	first_menu() ; 
	int num=login(fstu, fsta, flec);
	first_menu();
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
	return 0;
}