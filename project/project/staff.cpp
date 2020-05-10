#include"Manager.h"
void load_file(const char* filename, int& n, Information*& Person)
{
    fstream fin;
    fin.open(filename, ios::in);
    if (!fin.is_open())
    {
        cout << "           Can you not create file " << endl;
        return;
    }
    else {
        fin >> n;
        Person = new Information[n];
        for (int i = 0; i < n; i++)
        {
            char a[5];
            fin.getline(a, 3);
            getline(fin, Person[i].Class);
            getline(fin, Person[i].id);
            getline(fin, Person[i].password);
            getline(fin, Person[i].fullname);
            fin >> Person[i].dob.year;
            fin >> Person[i].dob.month;
            fin >> Person[i].dob.date;
            string s;
            getline(fin, s);
        }
    }
    fin.close();
}

void Importstudents()//filename= "student_"
{
    int num1;
    cout << "0 - Return" << endl;
    cout << "1 - Import students" << endl;
    cout << "You option : ";
    cin >> num1;
    while (num1 != 0)
    {
        cin.ignore();
        string classname;
        cout << "   Enter Classname:";
        getline(cin, classname);

        Information student[100];
        int n = 0;

        ifstream fcsv;

        string temp = "Student-" + classname + ".csv";
        const char* inputfilename = temp.c_str();

        fcsv.open(inputfilename);
        if (!fcsv.is_open())
        {
            cout << "   Import fail" << endl;
            return;
        }
        string a;
        getline(fcsv, a);
        int num;
        while (!fcsv.eof())
        {
            fcsv >> num;
            char c;
            fcsv >> c;
            getline(fcsv, student[n].id, ',');
            getline(fcsv, student[n].fullname, ',');
            fcsv >> student[n].dob.year;
            fcsv >> c;
            fcsv >> student[n].dob.month;
            fcsv >> c;
            fcsv >> student[n].dob.date;
            fcsv >> c;
            getline(fcsv, student[n].Class, '\n');
            string date;
            string month;
            if (student[n].dob.month < 10)
                month = "0" + to_string(student[n].dob.month);
            else
                month = to_string(student[n].dob.month);
            if (student[n].dob.date < 10)
                date = "0" + to_string(student[n].dob.date);
            else
                date = to_string(student[n].dob.date);
            student[n].password = to_string(student[n].dob.year) + month + date;
            student[n].type = 2;
            n++;
        }

        saveStudent(student, classname, n - 1);
        fcsv.close();

        cout << "You option : ";
        cin >> num1;
    }
}

void saveStudent(Information* student, string classname, int n)
{
    fstream f;
    string temp_1 = "Student-" + classname + ".txt";
    const char* outputfilename = temp_1.c_str();
    f.open(outputfilename, ios::out);

    f << n << endl;
    for (int i = 0; i < n; i++)
    {
        f << student[i].Class << endl;
        f << student[i].id << endl;
        f << student[i].dob.year;
        if (student[i].dob.month < 10)
            f << "0" << student[i].dob.month;
        else
            f << student[i].dob.month;
        if (student[i].dob.date < 10)
            f << "0" << student[i].dob.date << endl;
        else
            f << student[i].dob.date << endl;
        f << student[i].fullname << endl;
        f << student[i].dob.year << " ";
        if (student[i].dob.month < 10)
            f << "0" << student[i].dob.month << " ";
        else
            f << student[i].dob.month << " ";
        if (student[i].dob.date < 10)
            f << "0" << student[i].dob.date << endl << endl;
        else
            f << student[i].dob.date << endl << endl;
    }
    f.close();
}

void edit_student()
{
    int num1;
    Information* student;
    cout << "0 - Return" << endl;
    cout << "1 - Edit student " << endl;
    cout << "You choice : ";
    cin >> num1;
    while (num1 != 0)
    {
        int n = 0;
        string classname;
        string username;
        cin.ignore();
        cout << "   Enter class: ";
        getline(cin, classname);
        cout << "   Enter username(ID): ";
        getline(cin, username);
        string temp_1 = "Student-" + classname + ".txt";
        const char* filename = temp_1.c_str();
        load_file(filename, n, student);
        for (int i = 0; i < n; i++)
        {
            if (username == student[i].id)
            {
                int num2;
                cout << "   Edit student : " << endl;
                cout << "   0. Return." << endl;
                cout << "   1. Edit id." << endl;
                cout << "   2. Edit name." << endl;
                cout << "   3. Edit dob." << endl;
                cout << "   Your choice: ";
                cin >> num2;
                while (num2 != 0)
                {
                    switch (num2)
                    {
                    case 1:
                    {
                        cout << "       Enter new id: ";
                        cin.ignore();
                        getline(cin, student[i].id);
                        break;
                    }
                    case 2:
                    {
                        cout << "       Enter new name: ";
                        cin.ignore();
                        getline(cin, student[i].fullname);
                        break;
                    }
                    case 3:
                    {
                        cout << "       Enter new year: ";
                        cin >> student[i].dob.year;
                        cout << "       Enter new month: ";
                        cin >> student[i].dob.month;
                        cout << "       Enter new date: ";
                        cin >> student[i].dob.date;
                        break;
                    }
                    default:
                        break;
                    }
                    cout << "   Your choice:";
                    cin >> num2;
                }
            }
        }
        saveStudent(student, classname, n);
        delete[] student;
        cout << "Your choice: ";
        cin >> num1;
    }
}

void add_a_element_in_file(const char* filename, int n, Information*& Person, Information person)
{
    fstream fout;
    fout.open(filename, ios::out);
    if (!fout.is_open())
    {
        cout << "           Can you not create file " << endl;
        return;
    }
    else {
        fout << n + 1 << endl;
        for (int i = 0; i < n; i++)
        {
            fout << Person[i].Class << endl;
            fout << Person[i].id << endl;
            fout << Person[i].dob.year;
            if (Person[i].dob.month < 10)
                fout << "0" << Person[i].dob.month;
            else
                fout << Person[i].dob.month;
            if (Person[i].dob.date < 10)
                fout << "0" << Person[i].dob.date << endl;
            else
                fout << Person[i].dob.date << endl; // 20012207
            fout << Person[i].fullname << endl;
            fout << Person[i].dob.year << " ";
            if (Person[i].dob.month < 10)
                fout << "0" << Person[i].dob.month << " ";
            else
                fout << Person[i].dob.month << " ";
            if (Person[i].dob.date < 10)
                fout << "0" << Person[i].dob.date << endl;
            else
                fout << Person[i].dob.date << endl;
            fout << endl;
        }
        fout << person.Class << endl;
        fout << person.id << endl;
        fout << person.dob.year;
        if (person.dob.month < 10)
            fout << "0" << person.dob.month;
        else
            fout << person.dob.month;
        if (person.dob.date < 10)
            fout << "0" << person.dob.date << endl;
        else
            fout << person.dob.date << endl;
        fout << person.fullname << endl;
        fout << person.dob.year << " ";
        if (person.dob.month < 10)
            fout << "0" << person.dob.month << " ";
        else
            fout << person.dob.month << " ";
        if (person.dob.date < 10)
            fout << "0" << person.dob.date << endl;
        else
            fout << person.dob.date << endl;
        fout << endl;
    }
    fout.close();
}

void remove_a_element_in_file(const char* filename, int n, Information*& Person, Information person)
{
    fstream fout;
    fout.open(filename, ios::out);
    if (!fout.is_open())
    {
        cout << "           Can you not create file " << endl;
        return;
    }
    else {
        fout << n - 1 << endl;
        for (int i = 0; i < n; i++)
        {
            if (Person[i].id != person.id)
            {
                fout << Person[i].Class << endl;
                fout << Person[i].id << endl;
                fout << Person[i].dob.year;
                if (Person[i].dob.month < 10)
                    fout << "0" << Person[i].dob.month;
                else
                    fout << Person[i].dob.month;
                if (Person[i].dob.date < 10)
                    fout << "0" << Person[i].dob.date << endl;
                else
                    fout << Person[i].dob.date << endl;
                fout << Person[i].fullname << endl;
                fout << Person[i].dob.year << " ";
                if (Person[i].dob.month < 10)
                    fout << "0" << Person[i].dob.month << " ";
                else
                    fout << Person[i].dob.month << " ";
                if (Person[i].dob.date < 10)
                    fout << "0" << Person[i].dob.date << endl;
                else
                    fout << Person[i].dob.date << endl;
                fout << endl;
            }
        }
    }
    fout.close();
}

void add_student_into_file_student_and_flie_class(Information person)
{
    int n = 0;
    Information* Person;
    const char* filename_student = "Student.txt";
    load_file(filename_student, n, Person);
    add_a_element_in_file(filename_student, n, Person, person);
    delete[] Person;

    string filename_class = "Student-" + person.Class + ".txt";
    const char* filename = filename_class.c_str();
    load_file(filename, n, Person);
    add_a_element_in_file(filename, n, Person, person);
    delete[] Person;
}

void manually_add_a_new_student_to_a_class()
{
    int num;
    cout << "0 - Return" << endl;
    cout << "1 - add student" << endl;
    cout << "You option : ";
    cin >> num;
    while (num != 0)
    {
        int n;
        cout << "   0 - Return" << endl;
        cout << "   1 - 19APCS1" << endl;
        cout << "   2 - 19APCS2" << endl;
        cout << "   3 - 19CLC1" << endl;
        cout << "   4 - 19CLC2" << endl;
        cout << "   5 - 19CLC3" << endl;
        cout << "   6 - 19CLC4" << endl;
        cout << "   7 - 19CLC5" << endl;
        cout << "   8 - 19CLC6" << endl;
        cout << "   9 - 19CLC7" << endl;
        cout << "   10 - 19CLC8" << endl;
        cout << "   11 - 19CLC9" << endl;
        cout << "   12 - 19CLC10" << endl;
        cout << "   You option : ";
        cin >> n;
        while (n != 0)
        {
            Information person;
            cout << "       Enter ID : ";
            cin >> person.id;
            cin.ignore();
            cout << "       Enter full name : ";
            getline(cin, person.fullname);
            cout << "       Enter  year of birth :";
            cin >> person.dob.year;
            cout << "       Enter month of birth : ";
            cin >> person.dob.month;
            cout << "       Enter date of birth : ";
            cin >> person.dob.date;
            switch (n)
            {
            case 1:
                person.Class = "19APCS1";
                break;
            case 2:
                person.Class = "19APCS2";
                break;
            case 3:
                person.Class = "19CLC1";
                break;
            case 4:
                person.Class = "19CLC2";
                break;
            case 5:
                person.Class = "19CLC3";
                break;
            case 6:
                person.Class = "19CLC4";
                break;
            case 7:
                person.Class = "19CLC5";
                break;
            case 8:
                person.Class = "19CLC6";
                break;
            case 9:
                person.Class = "19CLC7";
                break;
            case 10:
                person.Class = "19CLC8";
                break;
            case 11:
                person.Class = "19CLC9";
                break;
            case 12:
                person.Class = "19CLC10";
                break;
            default:
                break;
            }
            add_student_into_file_student_and_flie_class(person);
            cout << "   You option : ";
            cin >> n;
        }
        cout << "You option : ";
        cin >> num;
    }
}

void remove_student_in_file_student_and_flie_class(Information person)
{
    int n = 0;
    Information* Person;
    const char* filename_student = "Student.txt";
    load_file(filename_student, n, Person);
    remove_a_element_in_file(filename_student, n, Person, person);
    delete[] Person;

    string filename_class = "Student-" + person.Class + ".txt";
    const char* filename = filename_class.c_str();

    load_file(filename, n, Person);
    remove_a_element_in_file(filename, n, Person, person);
    delete[] Person;

}

void remove_a_student()
{
    int num;
    cout << "0 - Return" << endl;
    cout << "1 - Remove student" << endl;
    cout << "You option : ";
    cin >> num;
    while (num != 0)
    {
        int n;
        cout << "   Remove student : " << endl;
        cout << "   0 - Return" << endl;
        cout << "   1 - 19APCS1" << endl;
        cout << "   2 - 19APCS2" << endl;
        cout << "   3 - 19CLC1" << endl;
        cout << "   4 - 19CLC2" << endl;
        cout << "   5 - 19CLC3" << endl;
        cout << "   6 - 19CLC4" << endl;
        cout << "   7 - 19CLC5" << endl;
        cout << "   8 - 19CLC6" << endl;
        cout << "   9 - 19CLC7" << endl;
        cout << "   10 - 19CLC8" << endl;
        cout << "   11 - 19CLC9" << endl;
        cout << "   12 - 19CLC10" << endl;
        cout << "   You option : ";
        cin >> n;
        while (n != 0)
        {
            Information person;
            cout << "       Enter ID : ";
            cin >> person.id;
            switch (n)
            {
            case 1:
                person.Class = "19APCS1";
                break;
            case 2:
                person.Class = "19APCS2";
                break;
            case 3:
                person.Class = "19CLC1";
                break;
            case 4:
                person.Class = "19CLC2";
                break;
            case 5:
                person.Class = "19CLC3";
                break;
            case 6:
                person.Class = "19CLC4";
                break;
            case 7:
                person.Class = "19CLC5";
                break;
            case 8:
                person.Class = "19CLC6";
                break;
            case 9:
                person.Class = "19CLC7";
                break;
            case 10:
                person.Class = "19CLC8";
                break;
            case 11:
                person.Class = "19CLC9";
                break;
            case 12:
                person.Class = "19CLC10";
                break;
            default:
                break;
            }
            remove_student_in_file_student_and_flie_class(person);
            cout << "   You option : ";
            cin >> n;
        }
        cout << "You option : ";
        cin >> num;
    }
}
//---------------------------------------------------------------COURSES----------------------------------------------------------------------------------------------------
//chuc nang 13: Tao mot hoc ky moi
void createSemester()
{
	ofstream fout;
	fout.open("semester.txt", ios::app);
	string academic_year;
	string semester;
	cout << "Enter academic_year: ";
	getline(cin, academic_year);
	cin.ignore();
	getline(cin, semester);
	fout << academic_year << endl;
	fout << semester << endl << endl;
}

//Cac xu ly ngay:
//-Tinh tong so ngay tu dau nam den ngay duoc nhap
int sum_day(Date date)
{
	int sum = 0;
	for (int i = 1; i < date.month; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			sum += 31;
		if (i == 4 || i == 6 || i == 9 || i == 11)
			sum += 30;
		else
			sum += month2(date);
	}
	return sum + date.date;
}
//-Cho ngay thang nam tim thu may trong tuan: 2:MON,3:TUE,4:WED,5:THU,6:FRI,7:SAT,8:SUN
int find_day_of_week(Date date)
{
	int sum = (date.year - 1) / 1 + (date.year - 1) / 4 - (date.year - 1) / 100 + (date.year - 1) / 400 + sum_day(date);
	int a = sum % 7;
	if (a == 0)
		return 8;
	else return a + 1;
}
//-Tinh so ngay cua thang hai
int month2(Date date)
{
	if (date.year % 4 == 0 && date.year % 100 != 0)
		return 29;
	return 28;
}
//-Tinh ra ngay ket qua khi cong so ngay vao ngay da cho
Date add_date(Date date, int numofday)
{
	Date result;
	if (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12)
	{
		if (numofday + date.date > 31)
		{
			result.date = numofday + date.date - 31;
			if (date.month == 12)
			{
				result.month = 1;
				result.year = date.year + 1;
			}
			else
			{
				result.month = date.month + 1;
				result.year = date.year;
			}
		}
		else
		{
			result.date = date.date + numofday;
			result.month = date.month;
			result.year = date.year;
		}
	}
	if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
	{
		if (numofday + date.date > 30)
		{
			result.date = numofday + date.date - 30;
			result.month = date.month + 1;
			result.year = date.year;
		}
		else
		{
			result.date = date.date + numofday;
			result.month = date.month;
			result.year = date.year;
		}
	}
	if (date.month == 2)
	{
		if (numofday + date.date > month2(date))
		{
			result.date = numofday + date.date - month2(date);
			result.month = date.month + 1;
			result.year = date.year;
		}
		else
		{
			result.date = date.date + numofday;
			result.month = date.month;
			result.year = date.year;
		}
	}
	return result;
}
//-Ngay dau tien bat dau buoi hoc khi biet nagy bat dau khoa hoc vaf buoi hoc vao thu may
Date first_lesson(Date startD, int dayofweek)// startD : start day, dayofweek: the day lesson occur on week.
{
	int distance_time = dayofweek - find_day_of_week(startD);
	if (distance_time < 0)
		distance_time += 7;
	return add_date(startD, distance_time);
}

//-Luu thong tin cac khoa hoc trong 1 hoc ky nam hoc
void saveCourses(string academic_year, string semester, string classname, course* Courses, int numofcourse)
{
	string temp = "D:\\filetest\\" + academic_year + "-" + semester + "-" + "schedule" + "-" + classname + ".txt";
	const char* filename = temp.c_str();
	ofstream fout;
	fout.open(filename);

	fout << numofcourse << endl;
	for (int i = 0; i < numofcourse; i++)
	{
		fout << Courses[i].ID << endl;
		fout << Courses[i].name << endl;
		fout << Courses[i].classname << endl;
		fout << Courses[i].lecture.id << endl;
		fout << Courses[i].lecture.fullname << endl;
		fout << Courses[i].lecture.degree << endl;
		fout << Courses[i].lecture.male << endl;
		fout << Courses[i].startD.date << " ";
		fout << Courses[i].startD.month << " ";
		fout << Courses[i].startD.year << endl;
		fout << Courses[i].endD.date << " ";
		fout << Courses[i].endD.month << " ";
		fout << Courses[i].endD.year << endl;
		fout << Courses[i].startH.hour << " ";
		fout << Courses[i].startH.minute << endl;
		fout << Courses[i].endH.hour << " ";
		fout << Courses[i].endH.minute << endl;
		fout << Courses[i].room << endl << endl;
	}
	fout.close();
}
//-Luu thong tin cua cac hoc sinh vao 1 khoa hoc
void saveStudentIntoACourse(Information* student, string filename, int numofstudent,course Course)
{
	ofstream fout;
	const char* outputfilename = filename.c_str();
	fout.open(outputfilename);
	fout << numofstudent << endl;

	Date list_date_of_course[10];
	list_date_of_course[0] = first_lesson(Course.startD, Course.dayofweek);
	for (int i = 1; i < 10; i++)
	{
		list_date_of_course[i] = add_date(list_date_of_course[i - 1], 7);
	}
	for (int i = 0; i < numofstudent; i++)
	{
		fout << student[i].Class << endl;
		fout << student[i].id << endl;
		fout << student[i].fullname << endl;
		fout << student[i].dob.date << " ";
		fout << student[i].dob.month << " ";
		fout << student[i].dob.year << endl;
		fout << 1 << endl;
		fout << -1 << endl;
		fout << -1 << endl;
		fout << -1 << endl;
		fout << -1 << endl;
		for (int j = 0; j < 10; j++)
		{
			fout << list_date_of_course[j].year << " " << list_date_of_course[j].month << " " << list_date_of_course[j].date << " ";
			fout << Course.startH.hour << " " << Course.startH.minute << " ";
			fout<< Course.endH.hour << " " << Course.endH.minute << " " << -1 << endl;
		}
		fout << endl;
	}
}
//-Luu thong tin cua hoc sinh vao tat ca cac khoa hoc
void saveStudentOfCourse(string academic_year, string semester, string classname, course* Courses, int numofcourse)
{
	int numofstudent;
	Information* student = NULL;
	loadStudent(student, classname, numofstudent);

	for (int i = 0; i < numofcourse; i++)
	{
		string filename ="D:\\filetest\\"+ academic_year + "-" + semester + "-" + classname + "-" + Courses[i].name + "-Student.txt";
		saveStudentIntoACourse(student, filename, numofstudent, Courses[i]);
	}
}

//Chuc nang 14: them khoa hoc
void ImportCourses()
{
	string academic_year, semester, classname, filename;
	cout << "Enter academic year:";
	getline(cin, academic_year,'\n');
	cout << "Enter semester :";
	getline(cin, semester, '\n');
	cout << "Enter class:";
	getline(cin, classname, '\n');
	cout << "Enter file name:";
	getline(cin, filename, '\n');

	course Courses[100];

	const char* temp = filename.c_str();
	ifstream fin;
	fin.open(temp);
	if (!fin.is_open())
	{
		cout << "File is not found !!";
		return;
	}

	string s;
	getline(fin, s);
	int numofcourses = 0;

	while (!fin.eof())
	{
		char c;
		fin >> Courses[numofcourses].no;
		fin >> c;
		getline(fin, Courses[numofcourses].ID, ',');
		getline(fin, Courses[numofcourses].name, ',');
		getline(fin, Courses[numofcourses].classname, ',');
		getline(fin, Courses[numofcourses].lecture.id, ',');
		getline(fin, Courses[numofcourses].lecture.fullname, ',');
		getline(fin, Courses[numofcourses].lecture.degree, ',');
		fin >> Courses[numofcourses].lecture.male;
		fin >> c;
		fin >> Courses[numofcourses].startD.date;
		fin >> c;
		fin >> Courses[numofcourses].startD.month;
		fin >> c;
		fin >> Courses[numofcourses].startD.year;
		fin >> c;
		fin >> Courses[numofcourses].endD.date;
		fin >> c;
		fin >> Courses[numofcourses].endD.month;
		fin >> c;
		fin >> Courses[numofcourses].dayofweek;
		fin >> c;
		fin >> Courses[numofcourses].endD.year;
		fin >> c;
		fin >> Courses[numofcourses].startH.hour;
		fin >> c;
		fin >> Courses[numofcourses].startH.minute;
		fin >> c;
		fin >> Courses[numofcourses].endH.hour;
		fin >> c;
		fin >> Courses[numofcourses].endH.minute;
		fin >> c;
		getline(fin, Courses[numofcourses].room);
		numofcourses++;
	}

	saveCourses(academic_year, semester, classname, Courses, numofcourses );
	saveStudentOfCourse(academic_year, semester, classname, Courses, numofcourses );
}




