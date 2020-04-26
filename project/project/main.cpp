#include "Manager.h"
#include <iostream>
using namespace std;
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
		switch(choice)

	}
	else if (num == 1)
	{
		int choice;
		show_menu_lecture();
		cout << "Choose option: ";
		cin >> choice;
		switch (choice)
	}
	else
	{
		int choice;
		show_menu_student;
		cout << "Choose option: ";
		cin >> choice;
		switch (choice)
	}
}