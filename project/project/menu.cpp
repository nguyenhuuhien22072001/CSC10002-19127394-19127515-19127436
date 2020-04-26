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
	cout << "-1 - Log out." << endl;
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
	cout << "-1 - Log out." << endl;
    cout << "0 - Check-in." << endl ; 
    cout << "1 - View check-in result." << endl ; 
    cout << "2 - View schedules."  << endl ;
    cout << "3 - View his/her scores of a course." << endl ;
}
void show_menu_staff() {
	cout << "-1 - Log out." << endl;
	cout << "0 - Import students of a class. " << endl;
	cout << "1 - Add a new student to a class. " << endl;
	cout << "2 - Edit an existing student. " << endl;
	cout << "3 - Remove a student. " << endl;
	cout << "4 - Change students from a class A to class B. " << endl;
	cout << "5 - View list of classes. " << endl;
	cout << "6 - View list of students in a class. " << endl;
	cout << "7 - Create / View academic years and semester." << endl;
	cout << "8 - Import courses from a semester." << endl;
	cout << "9 - Add a new course." << endl;
	cout << "10 - Edit an existing course. " << endl;
	cout << "11 - Remove a course." << endl;
	cout << "12 - Remove a specific student from a course." << endl;
	cout << "13 - Add a specific student to a course." << endl;
	cout << "14 - View list of courses in the current semester. " << endl;
	cout << "15 - View list of students of a course." << endl;
	cout << "16 - View attendance list of a course. " << endl;
	cout << "17 - Create / View all lecturers." << endl;
}
void showInfo(Information person) {
	cout << "Thong tin cua ban: " << endl;
	cout << "Ngay sinh: " << person.dob.date << "-" << person.dob.month << "-" << person.dob.year << endl;
	cout << "Gioi tinh: ";
	if (person.male == 0)
		cout << "nam" << endl;
	else
		cout << "nu" << endl;
	cout << "Chuc nang cua ban: ";
	if (person.type == 0)
		cout << "Giao vu" << endl;
	else if (person.type == 1)
		cout << "Giang vien" << endl;
	else
		cout << "Sinh vien" << endl;
}
int login(fstream& fstu, fstream& fsta, fstream& flec)
{
	string username;
	string password;
	cout << "Enter your User name: ";
	cin >> username;
	cout << "Enter your Password: ";
	cin >> password;

	int n;
	fstu >> n;
	Information* student = new Information[n];
	for (int i = 0; i < n; i++)
	{
		getline(fstu, student[i].id);
		cin.ignore();
		getline(fstu, student[i].password);
		cin.ignore();
		getline(fstu, student[i].fullname);
		fstu >> student[i].dob.date;
		fstu >> student[i].dob.month;
		fstu >> student[i].dob.year;
		fstu >> student[i].male;
		fstu >> student[i].type;
		if (username == student[i].id && password == student[i].password)
		{
			cout << "Xin chao hoc sinh " << student[i].fullname << endl;
			showInfo(student[i]);
			return 2;
		}
	}
	flec >> n;
	Information* lecture = new Information[n];
	for (int i = 0; i < n; i++)
	{
		getline(flec, lecture[i].id);
		cin.ignore();
		getline(flec, lecture[i].password);
		cin.ignore();
		getline(flec, lecture[i].fullname);
		flec >> lecture[i].dob.date;
		flec >> lecture[i].dob.month;
		flec >> lecture[i].dob.year;
		flec >> lecture[i].male;
		flec >> lecture[i].type;
		if (username == lecture[i].id && password == lecture[i].password)
		{
			cout << "Xin chao hoc sinh " << student[i].fullname << endl;
			showInfo(lecture[i]);
			return 1;
		}
	}
	fsta >> n;
	Information* staff = new Information[n];
	for (int i = 0; i < n; i++)
	{
		getline(fsta, staff[i].id);
		cin.ignore();
		getline(fsta, staff[i].password);
		cin.ignore();
		getline(fsta, staff[i].fullname);
		fsta >> staff[i].dob.date;
		fsta >> staff[i].dob.month;
		fsta >> staff[i].dob.year;
		fsta >> staff[i].male;
		fsta >> staff[i].type;
		if (username == staff[i].id && password == staff[i].password)
		{
			cout << "Xin chao hoc sinh " << student[i].fullname << endl;
			showInfo(staff[i]);
			return 0;
		}
	}
}
