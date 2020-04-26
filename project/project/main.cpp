#include "Manager.h"
int main()
{
	fstream fstu, fsta, flec;
	int num=login(fstu, fsta, flec);
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