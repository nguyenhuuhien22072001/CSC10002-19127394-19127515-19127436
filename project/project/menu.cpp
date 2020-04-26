#include "Manager.h"
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
	Information* student=new Information[n];
	for (int i=0;i<n;i++)
	{
		getline(fstu ,student [i].id);
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
