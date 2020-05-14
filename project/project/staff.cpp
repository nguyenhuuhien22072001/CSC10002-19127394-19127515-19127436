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
    cout << "Your choice : ";
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

void add_student_into_file_student_and_file_class(Information person)
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
    cout << "1 - Add student" << endl;
    cout << "Your option : ";
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
        cout << "   Your option : ";
        cin >> n;
        while (n != 0)
        {
            Information person;
            cout << "       Enter Student ID : ";
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
            add_student_into_file_student_and_file_class(person);
            cout << "   Your option : ";
            cin >> n;
        }
        cout << "Your option : ";
        cin >> num;
    }
}

void remove_student_in_file_student_and_file_class(Information person)
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
    cout << "Your option : ";
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
        cout << "   Your option : ";
        cin >> n;
        while (n != 0)
        {
            Information person;
            cout << "       Enter Student ID : ";
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
            remove_student_in_file_student_and_file_class(person);
            cout << "   Your option : ";
            cin >> n;
        }
        cout << "Your option : ";
        cin >> num;
    }
}
void loadstudent(Information& person) {
    Information* Person;
    int n;
    ifstream f;
    const char* filename_student = "Student.txt";
        load_file(filename_student, n, Person);
        for (int i = 0; i < n; i++) {
            if (Person[i].id == person.id) {
                person.Class = Person[i].Class;
                person.id = Person[i].id;
                person.password = Person[i].password;
                person.fullname = Person[i].fullname;
                person.dob.year = Person[i].dob.year;
                person.dob.month = Person[i].dob.month;
                person.dob.date = Person[i].dob.date;
            }    
    }
}
void change_student_to_another_class()
{
    int num;
    cout << "0 - Return" << endl;
    cout << "1 - Change Student's Class." << endl;
    cout << "Your option : ";
    cin >> num;
    while (num != 0)
    {
        int des;
        cout << "   Choose class to move in : " << endl;
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
        cin >> des;
        if (des != 0)
        {
            Information person;
            cout << "       Enter Student ID : ";
            cin >> person.id;
            loadstudent(person);
            remove_student_in_file_student_and_file_class(person);
            switch (des)
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
            add_student_into_file_student_and_file_class(person);
        }
        cout << "0 - Return" << endl;
        cout << "1 - Change Student's Class." << endl;
        cout << "Your option : ";
        cin >> num;
    }
}
void view_list_of_classes() {
    int num;
    cout << "0 - Return" << endl;
    cout << "1 - View list of classes." << endl; 
    cout << "Your option : ";
    cin >> num;
    while (num != 0)
    {   
        cout << "19APCS1" << endl;
        cout << "19APCS2" << endl;
        for (int i = 0; i < 10; i++) {
            cout << "19CLC" << i + 1;
        }
        cout << "0 - Return" << endl;
        cin >> num;
    }
}
void view_list_of_student() {
    int num;
    cout << "0 - Return" << endl;
    cout << "1 - View list of student in a class." << endl;
    cout << "Your option : ";
    cin >> num;
    while (num != 0) {
        int n;
        cout << "   Choose any class : " << endl;
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
        cin >> n;
        while (n != 0) {
            Information* person;
            int m;
            string Class;
            switch (n)
            {
            case 1:
                Class = "19APCS1";
                break;
            case 2:
                Class = "19APCS2";
                break;
            case 3:
                Class = "19CLC1";
                break;
            case 4:
                Class = "19CLC2";
                break;
            case 5:
                Class = "19CLC3";
                break;
            case 6:
                Class = "19CLC4";
                break;
            case 7:
                Class = "19CLC5";
                break;
            case 8:
                Class = "19CLC6";
                break;
            case 9:
                Class = "19CLC7";
                break;
            case 10:
                Class = "19CLC8";
                break;
            case 11:
                Class = "19CLC9";
                break;
            case 12:
                Class = "19CLC10";
                break;
            default:
                break;
            }
            string filename_class = "Student-" + Class + ".txt";
            const char* filename = filename_class.c_str();
            load_file(filename, m, person);
            for (int i = 0; i < m; i++) {
                cout << person[i].Class << endl;
                cout << person[i].id << endl;
                cout << person[i].password << endl;
                cout << person[i].fullname << endl;
                cout << person[i].dob.year;
                cout << person[i].dob.month;
                cout << person[i].dob.date;
            }
            cout << "0 - Return" << endl;
            cout << "1 - View another list of student in a class." << endl;
            cout << "Your option : ";
            cin >> n;
        }
    }
}
void loadStudent(Information*& student, string classname, int& n)
{
    fstream f;
    string temp_1 = "D:\\filetest\\Student-" + classname + ".txt";
    const char* inputfilename = temp_1.c_str();
    f.open(inputfilename, ios::in);

    f >> n;
    cout << n << endl;
    student = new Information[n];
    for (int i = 0; i < n; i++)
    {
        char a[5];
        f.getline(a, 3);
        getline(f ,student[i].Class);
        getline(f, student[i].id);
        getline(f, student[i].password);
        getline(f, student[i].fullname);
        f >> student[i].dob.year;
        f >> student[i].dob.month;
        f >> student[i].dob.date;
        string s;
        getline(f, s);
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

//Dua thong tin cua khoa hoc vao mang
void loadCourses(string academic_year, string semester, string classname, course*& Courses, int& numofcourses)
{
    string temp = "D:\\filetest\\" + academic_year + "-" + semester + "-" + "schedule" + "-" + classname + ".txt";
    const char* filename = temp.c_str();
    fstream fin;
    fin.open(filename, ios::in);
    fin >> numofcourses;
    Courses = new course[numofcourses];
    
    for (int i = 0; i < numofcourses; i++)
    {
        char a[5];
        fin.getline(a, 2);
        //string s;
        getline(fin, Courses[i].ID);
        getline(fin, Courses[i].name);
        getline(fin, Courses[i].classname);
        getline(fin, Courses[i].lecture.id);
        getline(fin, Courses[i].lecture.fullname);
        getline(fin, Courses[i].lecture.degree);
        fin >> Courses[i].lecture.male;
        fin >> Courses[i].startD.date;
        fin >> Courses[i].startD.month;
        fin >> Courses[i].startD.year;
        fin >> Courses[i].endD.date;
        fin >> Courses[i].endD.month;
        fin >> Courses[i].endD.year;
        fin >> Courses[i].dayofweek;
        fin >> Courses[i].startH.hour;
        fin >> Courses[i].startH.minute;
        fin >> Courses[i].endH.hour;
        fin >> Courses[i].endH.minute;
        getline(fin, Courses[i].room);
        getline(fin, Courses[i].room);
        //getline(fin, s);
    }
    fin.close();
}

//Dua thong tin cua hoc sinh trong 1 khoa hoc vao mang
void loadStudentOfACourse(string academic_year, string semester, string classname, string courseName, student_in_course *&student, int& numofstudent)
{
    string temp = "D:\\filetest\\" + academic_year + "-" + semester + "-" + classname + "-" + courseName + "-Student.txt";
    const char* filename = temp.c_str();
    ifstream fin;

    fin.open(filename);
    if (!fin.is_open())
    {
        cout << " Can not open file !!";
        return;
    }
    fin >> numofstudent;
    student = new student_in_course[numofstudent];

    for (int i = 0; i < numofstudent; i++)
    {
        char a[5];
        fin.getline(a, 3);
        getline(fin, student[i].Class);
        getline(fin, student[i].id);
        getline(fin, student[i].fullname);
        fin >> student[i].dob.year;
        fin >> student[i].dob.month;
        fin>> student[i].dob.date;
        fin >> student[i].active;
        fin >> student[i].mark.lab;
        fin >> student[i].mark.midterm;
        fin >> student[i].mark.final;
        fin >> student[i].mark.bonus;
        for (int j = 0; j < 10; j++)
        {
            fin >> student[i].date[j].year;
            fin >> student[i].date[j].month;
            fin >> student[i].date[j].date;
            fin >> student[i].StartTime[j].hour;
            fin >> student[i].StartTime[j].minute;
            fin >> student[i].EndTime[j].hour;
            fin >> student[i].EndTime[j].minute;
            fin >> student[i].check_in[j];
        }
        string s;
        getline(fin, s);
    }
    for (int i = 0; i < numofstudent; i++)
    {
        cout << student[i].id;
    }
    fin.close();
}
//luu thong tin cua sinh vien cua khoa hoc vao khoa hoc
void saveStudentOfACourse(string academic_year, string semester, string classname, string courseName, student_in_course* student, int numofstudent)
{
    string temp = "D:\\filetest\\" + academic_year + "-" + semester + "-" + classname + "-" + courseName + "-Student.txt";
    const char* filename = temp.c_str();
    ofstream fout;

    fout.open(filename,ios::out);
    if (!fout.is_open())
    {
        cout << "fail !!";
        return;
    }

    fout << numofstudent<<endl;
    for (int i = 0; i < numofstudent; i++)
    {
        fout << student[i].Class << endl;
        fout << student[i].id << endl;
        fout << student[i].fullname << endl;
        fout << student[i].dob.year<< " ";
        fout << student[i].dob.month << " ";
        fout << student[i].dob.date << endl;
        fout << student[i].active << endl;
        fout << student[i].mark.lab << endl;
        fout << student[i].mark.midterm << endl;
        fout << student[i].mark.final << endl;
        fout << student[i].mark.bonus << endl;
        for (int j = 0; j < 10; j++)
        {
            fout << student[i].date[j].year << " ";
            fout << student[i].date[j].month << " ";
            fout << student[i].date[j].date << " ";
            fout << student[i].StartTime[j].hour << " ";
            fout << student[i].StartTime[j].minute << " ";
            fout << student[i].EndTime[j].hour << " ";
            fout << student[i].EndTime[j].minute << " ";
            fout << student[i].check_in[j] << endl;
        }
        fout << endl;
    }
    fout.close();
}

//-Luu thong tin cac khoa hoc trong 1 hoc ky nam hoc
void saveCourses(string academic_year, string semester, string classname, course* Courses, int numofcourse)
{
	string temp = "D:\\filetest\\" + academic_year + "-" + semester + "-" + "schedule" + "-" + classname + ".txt";
	const char* filename = temp.c_str();
	ofstream fout;
	fout.open(filename,ios::out);

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
        fout << Courses[i].dayofweek << endl;
		fout << Courses[i].startH.hour << " ";
		fout << Courses[i].startH.minute << endl;
		fout << Courses[i].endH.hour << " ";
		fout << Courses[i].endH.minute << endl;
		fout << Courses[i].room << endl << endl;
	}
	fout.close();
}
//-Luu thong tin cua cac sinh vien tu lop sinh hoat vao 1 khoa hoc
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
    cout << numofstudent;
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
		fin >> Courses[numofcourses].endD.year;
		fin >> c;
        fin >> Courses[numofcourses].dayofweek;
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

//Chuc nang 15: them khoa hoc vào danh sach
void Add_Course()
{
    string academic_year, semester, classname;
    int numofcourses;
    course* Courses_1 = NULL;

    cout << "Enter academic year: ";
    getline(cin, academic_year);

    cout << "Enter semesster :";
    getline(cin, semester);

    cout << "Enter classname: ";
    getline(cin, classname);

    loadCourses(academic_year, semester, classname, Courses_1, numofcourses);

    course* Courses_2 = new course[numofcourses + 1];

    for (int i = 0; i < numofcourses; i++)
        Courses_2[i] = Courses_1[i];
    cout << "Enter Information of course: " << endl;
    cout << "   Enter ID of course:";
    getline(cin, Courses_2[numofcourses].ID);
    cout << "   Enter name of course: ";
    getline(cin, Courses_2[numofcourses].name);
    cout << "   Enter class name: ";
    getline(cin, Courses_2[numofcourses].classname);
    cout << "   Enter lecture ID: ";
    getline(cin, Courses_2[numofcourses].lecture.id);
    cout << "   Enter lecture name: ";
    getline(cin, Courses_2[numofcourses].lecture.fullname);
    cout << "   Enter degree of lecture:";
    getline(cin, Courses_2[numofcourses].lecture.degree);
    cout << "   Enter male of lecture (1.female,2.male): ";
    cin >> Courses_2[numofcourses].lecture.male;
    cout << "   Enter start day of course: ";
    cin >> Courses_2[numofcourses].startD.date;
    cin >> Courses_2[numofcourses].startD.month;
    cin >> Courses_2[numofcourses].startD.year;
    cout << "   Enter end day of course: ";
    cin >> Courses_2[numofcourses].endD.date;
    cin >> Courses_2[numofcourses].endD.month;
    cin >> Courses_2[numofcourses].endD.year;
    cout << "   Enter day of week(2.MON,3.TUE,4.WED,5.THU,6.FRI,7.STA,8.SUN): ";
    cin >> Courses_2[numofcourses].dayofweek;
    cout << "   Enter start hour: ";
    cin >> Courses_2[numofcourses].startH.hour;
    cin >> Courses_2[numofcourses].startH.minute;
    cout << "   Enter end hour: ";
    cin >> Courses_2[numofcourses].endH.hour;
    cin >> Courses_2[numofcourses].endH.minute;
    cout << "   Enter rom: ";
    cin.ignore();
    getline(cin, Courses_2[numofcourses].room);

    saveCourses(academic_year, semester, classname, Courses_2, numofcourses + 1);
}
//Chuc nang 16: chinh sua khoa hoc
void Edit_a_course()
{
    string academic_year, semester, classname, nameofcourse;
    int numofcourses;
    course* Courses = NULL;

    cout << "Enter academic year: ";
    getline(cin, academic_year);

    cout << "Enter semesster: ";
    getline(cin, semester);

    cout << "Enter classname: ";
    getline(cin, classname);

    cout << "Enter name of course: ";
    getline(cin, nameofcourse);

    loadCourses(academic_year, semester, classname, Courses, numofcourses);

    for (int i = 0; i < numofcourses; i++)
    {
        if (nameofcourse == Courses[i].name)
        {
            int num;
            do
            {
                cout << "-1 - Exit";
                cout << "0 - Edit ID" << endl;
                cout << "1 - Edit name of course" << endl;
                cout << "2 - Edit class name" << endl;
                cout << "3 - Edit ID of lecture" << endl;
                cout << "4 - Edit name of lecture" << endl;
                cout << "5 - Edit degree of lecture" << endl;
                cout << "6 - Edit male of lecture" << endl;
                cout << "7 - Edit  start day" << endl;
                cout << "8 - Edit end day" << endl;
                cout << "9 - Edit start hour" << endl;
                cout << "10 - Edit end hour" << endl;
                cout << "11 - Edit room" << endl;

                cout << "Your choice: ";
                cin >> num;
                cin.ignore();

                switch (num)
                {
                case 0:
                {
                    getline(cin, Courses[i].ID);
                    break;
                }
                case 1:
                {
                    getline(cin, Courses[i].name);
                    break;
                }
                case 2:
                {
                    getline(cin, Courses[i].classname);
                    break;
                }
                case 3:
                {
                    getline(cin, Courses[i].lecture.id);
                    break;
                }
                case 4:
                {
                    getline(cin, Courses[i].lecture.fullname);
                    break;
                }
                case 5:
                {
                    getline(cin, Courses[i].lecture.degree);
                    break;
                }
                case 6:
                {
                    cin >> Courses[i].lecture.male;
                    break;
                }
                case 7:
                {
                    cin >> Courses[i].startD.date;
                    cin >> Courses[i].startD.month;
                    cin >> Courses[i].startD.year;
                    break;
                }
                case 8:
                {
                    cin >> Courses[i].endD.date;
                    cin >> Courses[i].endD.month;
                    cin >> Courses[i].endD.year;
                    break;
                }
                case 9:
                {
                    cin >> Courses[i].startH.hour;
                    cin >> Courses[i].startH.minute;
                    break;
                }
                case 10:
                {
                    cin >> Courses[i].endH.hour;
                    cin >> Courses[i].endH.minute;
                    break;
                }
                case 11:
                {
                    getline(cin, Courses[i].room);
                    break;
                }
                default:
                {
                    cout << "Your choice inavalid !!";
                    break;
                }
                }
            } while (num != -1);
            
        }

    }
    saveCourses(academic_year, semester, classname, Courses, numofcourses);
}
//Chuc nang 17: Xoa khoa hoc
void Remove_course()
{
    string academic_year, semester, classname, courseID;
    int numofcourses;
    course* Courses = NULL;

    cout << "Enter academic year: ";
    getline(cin, academic_year);

    cout << "Enter semesster :";
    getline(cin, semester);

    cout << "Enter classname";
    getline(cin, classname);

    cout << "Enter course ID: ";
    getline(cin, courseID);

    loadCourses(academic_year, semester, classname, Courses, numofcourses);
    bool check = false;
    for (int i = 0; i < numofcourses; i++)
    {
        if (courseID == Courses[i].ID)
            check = true;
        if (check == true)
        {
            if (i == numofcourses - 1)
                break;
            Courses[i] = Courses[i + 1];
        }
    }
    if (check == true)
        saveCourses(academic_year, semester, classname, Courses, numofcourses-1);
    else
        cout << "Not found ID of course " << endl;
}
//Chuc nang 18: Xoa 1 sv ra khoi khoa hoc
void Remove_student_from_a_course()
{
    string academic_year, semester, classname, courseName, studentID;
    int numofstudent;
    student_in_course* student = NULL;

    cout << "Enter academic year: ";
    getline(cin, academic_year);

    cout << "Enter semesster :";
    getline(cin, semester);

    cout << "Enter classname";
    getline(cin, classname);

    cout << "Enter course name: ";
    getline(cin, courseName);

    cout << "Enter ID of student removed";
    getline(cin, studentID);

    loadStudentOfACourse(academic_year, semester, classname, courseName, student, numofstudent);

    bool check = false;
    for (int i = 0; i < numofstudent; i++)
    {
        if (student[i].id == studentID)
        {
            student[i].active = -1;
            check = true;
        }
    }
    if (check == true)
        saveStudentOfACourse(academic_year, semester, classname, courseName, student, numofstudent);
    else
        cout << "Student ID is not found";
}
//Chuc nang 19: Them sinh vao khoa hoc
void Add_student_into_course()
{
    string academic_year, semester, classname, courseName;
    int numofstudent;
    student_in_course* student = NULL;

    cout << "Enter academic year: ";
    getline(cin, academic_year);

    cout << "Enter semesster :";
    getline(cin, semester);

    cout << "Enter classname";
    getline(cin, classname);

    cout << "Enter course name: ";
    getline(cin, courseName);

    loadStudentOfACourse(academic_year, semester, classname, courseName, student, numofstudent);
    
    student_in_course* student_1 = new student_in_course[numofstudent+1];

    for (int i = 0; i < numofstudent; i++)
        student_1[i] = student[i];
    cout << " Enter Information of this student: " << endl;

    cout << "Enter class name: ";
    getline(cin, student_1[numofstudent].Class);

    cout << "Enter ID of student: ";
    getline(cin, student_1[numofstudent].id);

    cout << "Enter fullname of student: ";
    getline(cin, student_1[numofstudent].fullname);
 

    cout << "Enter date of birth: ";
    cin >> student_1[numofstudent].dob.year;
    cin >> student_1[numofstudent].dob.month;
    cin >> student_1[numofstudent].dob.date;

    student_1[numofstudent].active = 1;
    student_1[numofstudent].mark = student_1[numofstudent - 1].mark;
    for (int j = 0; j < 10; j++)
    {
        student_1[numofstudent].date[j] = student_1[numofstudent - 1].date[j];
        student_1[numofstudent].StartTime[j] = student_1[numofstudent - 1].StartTime[j];
        student_1[numofstudent].EndTime[j] = student_1[numofstudent - 1].EndTime[j];
        student_1[numofstudent].check_in[j] = student_1[numofstudent - 1].check_in[j];
    }
    saveStudentOfACourse(academic_year, semester, classname, courseName, student_1, numofstudent + 1);

}
//Chuc nang 20: Xem danh sach khoa hoc trong HK hien tai
void View_list_courses()
{
    string academic_year, semester, classname;
    int numofcourses;
    course* Courses = NULL;

    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter classname: ";
    getline(cin, classname);

    loadCourses(academic_year, semester, classname, Courses, numofcourses);

    for (int i = 0; i < numofcourses; i++)
    {
        cout << i + 1 << " . ";
        cout << Courses[i].ID << " , ";
        cout << Courses[i].name << " , ";
        cout << Courses[i].lecture.id << " , ";
        cout << Courses[i].lecture.fullname << " , ";
        cout << Courses[i].lecture.degree << " , ";
        cout << Courses[i].lecture.male << endl;
    }
}
//Chuc nang 21: Xem danh sach sinh vien cua khoa hoc
void View_list_students_of_course()
{
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    cout << "Enter course name: ";
    getline(cin, coursename);

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
    cout << "List of students in course " << coursename << " :" << endl;
    for (int i = 0; i < numofstudent; i++)
        cout << student[i].id << "." << student[i].fullname << endl;
}
//Chuc nang 24: Xem bang diem
void View_scoreboard_course()
{
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    cout << "Enter course name: ";
    getline(cin, coursename);

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
    cout << "Scoreboard of course " << coursename << " :" << endl;
    cout << "ID\t\tFull name\tLab\tMidterm\tFinal\tBonus" << endl;
    for (int i = 0; i < numofstudent; i++)
    {
        cout << student[i].id << "\t\t" << student[i].fullname << "\t";
        cout << student[i].mark.lab << "\t" << student[i].mark.midterm << "\t" << student[i].mark.final << "\t" << student[i].mark.bonus << endl;
    }
}
//Chuc nang 25: Luu bang diem
void save_scoreboard()
{
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    cout << "Enter course name: ";
    getline(cin, coursename);

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);

    char filecsv[101];
    cout << "Enter name of csv file: ";
    cin.getline(filecsv, 101);
    ofstream fout;
    fout.open(filecsv);
    if (!fout.is_open())
    {
        cout << "Can not create csv file";
        return;
    }
    fout << "ID,full name,lab,midterm,final,bonus" << endl;
    for (int i = 0; i < numofstudent; i++)
        fout << student[i].id << "," << student[i].fullname << "," << student[i].mark.lab << "," << student[i].mark.midterm << "," << student[i].mark.final << "," << student[i].mark.bonus << endl;
    fout.close();
}
//Chuc nang 26: Xem bang diem danh
void View_export_attendance_list()
{
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    cout << "Enter course name: ";
    getline(cin, coursename);

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);
    cout << "Attendance list of course " << coursename << " :" << endl;
    cout << "ID\t\tFull name\tBuoi 1\tBuoi 2\tBuoi 3\tBuoi 4\tBuoi 5\tBuoi 6\tBuoi 7\tBuoi 8\tBuoi 9\tBuoi 10" << endl;
    for (int i = 0; i < numofstudent; i++)
    {
        cout << student[i].id << "\t\t" << student[i].fullname << "\t";
        for (int j = 0; j < 10; j++)
            cout << student[j].check_in[i] << "\t";
        cout << endl;
    }
}
//Chuc nang 27: Luu vao file csv
void save_attendance_list()
{
    string academic_year, semester, classname, coursename;
    cout << "Enter academic year: ";
    getline(cin, academic_year);
    cout << "Enter semester: ";
    getline(cin, semester);
    cout << "Enter class name: ";
    getline(cin, classname);
    cout << "Enter course name: ";
    getline(cin, coursename);

    student_in_course* student = NULL;
    int numofstudent;
    loadStudentOfACourse(academic_year, semester, classname, coursename, student, numofstudent);

    char filecsv[101];
    cout << "Enter name of csv file: ";
    cin.getline(filecsv, 101);
    ofstream fout;
    fout.open(filecsv);
    if (!fout.is_open())
    {
        cout << "Can not create csv file";
        return;
    }
    fout << "ID,full name,lab,midterm,final,bonus" << endl;
    for (int i = 0; i < numofstudent; i++)
        fout << student[i].id << "," << student[i].fullname << "," << student[i].mark.lab << "," << student[i].mark.midterm << "," << student[i].mark.final << "," << student[i].mark.bonus << endl;
    fout.close();
}




