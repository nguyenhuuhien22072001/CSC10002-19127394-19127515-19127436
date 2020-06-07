#include "Manager.h"
void  first_menu()
{
   int n ;  
   cout << "0 - Log out" << endl ; 
   cout << "1 - Log in " << endl ; 
   cout << " You option :" ;
   cin >> n  ; 
   if (n == 0)
       exit ;
}
int login(fstream& fstu, fstream& fsta, fstream& flec , Information & person)
{
	string username;
	string password;
	cout << "Enter your User name: ";
	getline(cin , username);
	cout << "Enter your Password: ";
	getline(cin , password); 

	int n;
	fstu.open("D:\\filetest\\Student.txt" , ios :: in); 
	if (!fstu.is_open())
	{
		cout << " fail";
		return -1;
	}
	fstu >> n;
	Information* student = new Information[n];
	for (int i = 0; i < n; i++)
	{
		char a[5];
		fstu.getline(a, 3);
		getline(fstu , student[i].Class);
		getline(fstu, student[i].id);
		getline(fstu, student[i].password);
		getline(fstu, student[i].fullname);
		fstu >> student[i].dob.year;

		fstu >> student[i].dob.month;
		fstu >> student[i].dob.date ;

		string s ; 
		getline(fstu , s);
		if (username == student[i].id && password == student[i].password)
		{
			cout << "Xin chao hoc sinh " << student[i].fullname << endl;
			person = student[i] ;
			fstu.close();
			delete [] student ;
			return 2;
		}
	}
	fstu.close();
	delete[] student;
	flec.open("D:\\filetest\\Lecture.txt" , ios :: in);
	flec >> n;
	Information* lecture = new Information[n];
	for (int i = 0; i < n; i++)
	{
		char a[5];
		flec.getline(a, 3);
		getline(flec, lecture[i].id);
		getline(flec, lecture[i].password);
		getline(flec, lecture[i].fullname);
		getline(flec, lecture[i].degree);
		flec >> lecture[i].male;
		string s ; 
		getline(flec , s);
		if (username == lecture[i].id && password == lecture[i].password)
		{
			cout << "Xin chao Giang vien " << lecture[i].fullname << endl;
			person = lecture[i] ;
			flec.close();
			delete [] lecture ;
			return 1;
		}
	}
	flec.close();
	delete[] lecture;
	fsta.open("D:\\filetest\\Staff.txt" , ios :: in);
	fsta >> n;
	Information* staff = new Information[n];
	for (int i = 0; i < n; i++)
	{
		char a[5];
		fsta.getline(a, 3);
		getline(fsta, staff[i].id);
		getline(fsta, staff[i].password);
		getline(fsta, staff[i].fullname);
		fsta >> staff[i].male;
		string s ; 
		getline(fsta , s);
		if (username == staff[i].id && password == staff[i].password)
		{
			cout << "Xin chao Giao vu " << staff[i].fullname << endl;
			person = staff[i] ;
			fsta.close();
			delete [] staff ;
			return 0;
		}
	}
	fsta.close();
	delete[] staff;
	return -1;
}
void show_menu_lecturer()
{
	cout << "MENU LECTURERS" << endl ;
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
	cout << "MENU STAFF" << endl ;
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
void showInfo_staff(Information person) 
{
	cout << "Thong tin cua ban: " << endl;
	cout << "Ho va ten" <<  person.fullname  << endl ;
	cout << "Gioi tinh: ";
	if (person.male == 0)
		cout << "Nam" << endl;
	else
		cout << "Nu" << endl;
	cout << "Chuc nang cua ban: Giao vu ";
}
void showInfo_lecturer(Information person)
{
	cout << "Thong tin cua ban: " << endl;
	cout << "Ho va ten" <<  person.fullname  << endl ;
	cout << "Gioi tinh: ";
	if (person.male == 0)
		cout << "Nam" << endl;
	else
		cout << "Nu" << endl;
	cout << "Chuc nang cua ban: Giang vien " << endl ;
	cout << "Trinh do: " << person.degree << endl ;
}
void showInfo_student(Information person)
{
	cout << "Thong tin cua ban: " << endl;
	cout << "Lop: " << person.Class  << endl ;
	cout << "ID: " << person.id << endl ;
	cout << "Ho va ten" <<  person.fullname  << endl ;
	cout << "Ngay sinh: " << person.dob.year << "-" ;
	if(person.dob.month < 10)
		cout << "0" << person.dob.month << "-" ;
	else	
		cout << person.dob.month << "-" ;
	if(person.dob.date < 10)
		cout << "0" << person.dob.date << endl ;
	else
		cout << person.dob.date << endl ;
	
}

void check_password(Information &person , string &pass)
{
        cout << "Enter new password : ";
        cin >> person.password ;
        cout << "Enter again new password : ";
        cin >> pass ;
        if(pass == person.password)
        {
            cout << "Change password successfully ." << endl;
            return ;
        }
        else
        {
            cout << "Enter new password failly , Enter again" << endl ;
            return check_password(person , pass);
        }
}
void change_password(Information &person)
{
    string pass ;
    cout << "Enter old password : " ;
    cin >> pass ;
	if (pass == person.password)
	{

		check_password(person, pass);

		while (pass != person.password)
		{
			cout << "password not match  " << endl;
			cout << "Enter old password : ";
			cin >> pass;
			if (pass == person.password)
				check_password(person, pass);
		}


		while (pass != person.password)
		{
			cout << "password not match  " << endl;
			cout << "Enter old password : ";
			cin >> pass;
			if (pass == person.password)
				check_password(person, pass);
		}
	}

}
void saveChangePassword(Information person)
{
    int n = 0 ;
    Information * Student ;
    string temp = "Student-" + person.Class + ".txt" ;
    const char * filename1 = temp.c_str() ;
    load_file(filename1, n, Student) ;
    for(int i = 0 ; i < n ; i++)
    {
        if(Student[i].id == person.id)
        {
            Student[i].password = person.password ;
            break ;
        }
    }
    saveStudent(Student, filename1 ,  n) ;
    delete [] Student ;
    const char * filename2 = "Student.txt" ;
    load_file(filename2, n, Student);
    for(int i = 0 ; i < n ; i++)
    {
        if(Student[i].id == person.id)
        {
            Student[i].password = person.password ;
            break ;
        }
    }
    saveStudent(Student, filename2, n);
    delete [] Student ;
}

