#include"Manager.h"
void loadStudent(Information*& student, string classname, int& n)
{
	fstream fin;
	string temp_1 = "D:\\filetest\\Student-" + classname + ".txt";
	const char* filename = temp_1.c_str();
	cout << filename << endl;
	fin.open(filename, ios::in);
	if (!fin.is_open())
	{
		cout << "fail0";
		return;
	}
	else
	{
		fin >> n;
		student = new Information[n];
		for (int i = 0; i < n; i++)
		{
			char ss[5];
			fin.getline(ss, 3);
			getline(fin, student[i].Class);
			getline(fin, student[i].id);
			getline(fin, student[i].password);
			getline(fin, student[i].fullname);
			fin >> student[i].dob.date;
			fin >> student[i].dob.month;
			fin >> student[i].dob.year;
			string s;
			getline(fin, s, '\n');
		}
		fin.close();
	}
}
void saveStudent(Information* student, string classname, int n)
{
	fstream f;
	string temp_1 = "D:\\filetest\\Student-" + classname + ".txt";
	const char* outputfilename = temp_1.c_str();
	f.open(outputfilename, ios::out);

	f << n << endl;
	for (int i = 0; i < n; i++)
	{
		f << student[i].Class << endl;
		f << student[i].id << endl;
		f << student[i].password << endl;
		f << student[i].fullname << endl;
		f << student[i].dob.date << " ";
		f << student[i].dob.month << " ";
		f << student[i].dob.year << endl << endl;
		f << 1;
	}
	f.close();
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

