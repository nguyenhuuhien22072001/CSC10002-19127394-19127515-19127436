
#include "Manager.h"
void Importstudents(fstream& fstu, string classname)//filename= "student_"
{
	Information student[100];
	int n = 0;
	ifstream fcsv;
	string temp = "Student-" + classname + ".csv";
	const char* inputfilename = temp.c_str();
	fcsv.open(inputfilename);
	ofstream ftxt;
	string temp_1 = "Student-" + classname + ".txt";
	const char* outputfilename = temp_1.c_str();
	ftxt.open(outputfilename);
	while (!fcsv.eof())
	{
		getline(fcsv, student[n].id,',');
		getline(fcsv, student[n].fullname, ',');
		int a;
		char c;
		fcsv >> a;
		student[n].dob.year = a % 10000;
		student[n].dob.month = (a / 10000) % 100;
		student[n].dob.date = a / 1000000;
		fcsv >> c;
		fcsv >> student[n].male;
		student[n].password = to_string(a);
		student[n].type = 2;
		n++;
	}
	ftxt << n << endl;
	for (int i = 0; i <= n; i++)
	{
		fstu << student[i].id << endl;
		fstu << student[i].password << endl;
		fstu << student[i].fullname << endl;
		fstu << student[i].dob.date << " ";
		fstu << student[i].dob.month << " ";
		fstu << student[i].dob.year << endl;
		fstu << student[i].male << endl;
		fstu << student[i].type << endl;
		fstu << 1 << endl << endl;

		ftxt << student[i].id << endl;
		ftxt << student[i].password << endl;
		ftxt << student[i].fullname << endl;
		ftxt << student[i].dob.date << " ";
		ftxt << student[i].dob.month << " ";
		ftxt << student[i].dob.year << endl;
		ftxt << student[i].male << endl;
		ftxt << student[i].type << endl;
		ftxt << 1 << endl << endl;
	}
	fcsv.close();
	ftxt.close();
}

void edit_student(fstream& fstu)
{
	
	char Class[7];
	string username;
	int n;

	cout << "Enter class: ";
	cin.getline(Class, 7);
	
	cout << "Enter username(ID): ";
	cin.ignore();
	getline(cin, username);
	
	fstu.seekg(0, ios ::beg);
	fstu >> n;
	Information* student = new Information[n];
	for (int i = 0; i < n; i++)
	{
		getline(fstu, student[i].id);
		getline(fstu, student[i].password);
		getline(fstu, student[i].fullname);
		fstu >> student[i].dob.date;
		fstu >> student[i].dob.month;
		fstu >> student[i].dob.year;

		fstu >> student[i].male;
		fstu >> student[i].type;
		if (username==student[i].id )
		{
			int num;
			cout << "1. Edit id." << endl;
			cout << "2. Edit name." << endl;
			cout << "3. Edit dob." << endl;
			cout << "4. Edit Active" << endl;
			cout << "Your choice: ";
			cin >> num;
			switch (num)
			{
			case 1:
			{
				cout << "Enter new id: ";
				cin.ignore();
				getline(cin, student[i].id);
			}
			case 2:
			{
				cout << "Enter new id: ";
				cin.ignore();
				getline(cin, student[i].id);
			}
			case 3:
			{
				cout << "Enter new id: ";
				cin.ignore();
				getline(cin, student[i].id);
			}
			}

		}
	}
}

void load_file(fstream &fin , const char* filename , int &n ,  Information* &Person)
{
	fin.open(filename);
	if(!fin.is_open())
	{
		cout << "Can you not create file "<< endl ; 
		fin.close(); 
		return ;
	}
	else {
		fin >> n;
		Person = new Information[n];
		for(int i = 0 ; i< n ; i++)
		{
			char a[5];
			fin.getline(a , 3);
			getline(fin , Person[i].Class);
			getline(fin , Person[i].id);
			getline(fin , Person[i].password);
			getline(fin , Person[i].fullname);
			fin >> Person[i].dob.year ; 
			fin >> Person[i].dob.month ; 
			fin >> Person[i].dob.date ; 
			string s ; 
			getline(fin , s);
		}
	}
	fin.close();
}

void load_file(fstream &fin , const char * filename , int &n ,  Information* &Person )
{
    fin.open(filename , ios :: in );
    if(!fin.is_open())
    {
        cout << "Can you not create file "<< endl ;
        return ;
    }
    else {
        fin >> n;
        Person = new Information[n];
        for(int i = 0 ; i< n ; i++)
        {
            char a[5];
            fin.getline(a ,3);
            getline(fin , Person[i].Class);
            getline(fin , Person[i].id);
            getline(fin , Person[i].password);
            getline(fin , Person[i].fullname);
            fin >> Person[i].dob.year ;
            fin >> Person[i].dob.month ;
            fin >> Person[i].dob.date ;
            string s ;
            getline(fin , s);
        }
    }
    fin.close();
}
void add_a_element_in_file(fstream &fout , const char * filename ,  int n , Information* &Person , Information person)
{
    fout.open(filename  , ios:: out);
    if(!fout.is_open())
    {
        cout << "Can you not create file "<< endl ;
        fout.close();
        return ;
    }
    else {
    fout << n+1 << endl ;
        for(int i = 0 ; i< n ; i++)
        {
            fout << Person[i].Class << endl ;
            fout << Person[i].id << endl;
            fout << Person[i].dob.year;
            if (Person[i].dob.month < 10)
                fout << "0" << Person[i].dob.month;
            else
                fout << Person[i].dob.month;
            if(Person[i].dob.date < 10)
                fout<< "0" << Person[i].dob.date << endl;
            else
                fout<< Person[i].dob.date << endl  ; // 20012207
            fout << Person[i].fullname << endl;
            fout << Person[i].dob.year << " " ;
            if (Person[i].dob.month < 10)
                fout << "0" << Person[i].dob.month << " " ;
            else
                fout << Person[i].dob.month;
            if(Person[i].dob.date < 10)
                fout<< "0" << Person[i].dob.date << endl;
            else
                fout<< Person[i].dob.date << endl  ;
            fout <<  endl ;
        }
        fout << person.Class << endl ;
        fout << person.id << endl ;
        fout << person.dob.year ;
        if(person.dob.month < 10)
            fout <<"0" << person.dob.month;
        else
            fout << person.dob.month;
        if(person.dob.date < 10)
            fout << "0" << person.dob.date  << endl ;
        else
            fout << person.dob.date  << endl ;
        fout << person.fullname<< endl;
        fout << person.dob.year << " ";
        if(person.dob.month < 10)
            fout <<"0" << person.dob.month << " ";
        else
            fout << person.dob.month << " ";
        if(person.dob.date < 10)
            fout << "0" << person.dob.date  << endl ;
        else
            fout << person.dob.date  << endl ;
        fout << endl ;
    }
    fout.close();
}

void add_element_into_file_student (Information person , fstream &fout)
{
    Information *Person ;
    const char * filename = "Student.txt";
    int n= 0 ;
    load_file(fout , filename ,n , Person);
    add_a_element_in_file(fout , filename , n , Person , person);
    delete [] Person ;
}

void add_element_into_file_class (Information person , fstream &fout)
{    int n = 0 ;
    Information *Person ;

    string temp = "Student_" + person.Class + ".txt";
    const char*filename = temp.c_str();

    load_file(fout , filename , n ,Person ) ;
    add_a_element_in_file(fout , filename , n , Person , person);
    delete [] Person ;
}

void add_student_into_file_student_and_flie_class( int n ,fstream &fstu , Information person , fstream &apcs1 , fstream &apcs2 , fstream &clc1 , fstream &clc2 , fstream &clc3 , fstream &clc4 , fstream &clc5 ,fstream &clc6 ,  fstream &clc7 , fstream &clc8 , fstream &clc9 , fstream &clc10)
{
    add_element_into_file_student(person , fstu);
    switch (n)
        {
        case 1:
            add_element_into_file_class(person , apcs1);
            break;
        case 2:
            add_element_into_file_class(person , apcs2);
            break;
        case 3:
            add_element_into_file_class(person , clc1);
            break;
        case 4:
            add_element_into_file_class(person , clc2);
            break;
        case 5:
            add_element_into_file_class(person , clc3);
            break;
        case 6:
            add_element_into_file_class(person , clc4);
            break;
        case 7:
            add_element_into_file_class(person , clc5);
            break;
        case 8:
            add_element_into_file_class(person , clc6);
            break;
        case 9:
            add_element_into_file_class(person , clc7);
            break;
        case 10:
            add_element_into_file_class(person , clc8);
            break;
        case 11:
            add_element_into_file_class(person , clc9);
            break;
        case 12:
            add_element_into_file_class(person , clc10);
            break;
        default:
            break;
        }
}

void manually_add_a_new_student_to_a_class(fstream &fstu  , fstream &apcs1 , fstream &apcs2 , fstream &clc1 , fstream &clc2 , fstream &clc3 , fstream &clc4 , fstream &clc5 ,fstream &clc6 ,  fstream &clc7 , fstream &clc8 , fstream &clc9 , fstream &clc10)
{
    int n ;
    cout << "0 - Return" << endl ;
    cout << "1 - 19APCS1" << endl ;
    cout << "2 - 19APCS2" << endl ;
    cout << "3 - 19CLC1" << endl ;
    cout << "4 - 19CLC2" << endl ;
    cout << "5 - 19CLC3" << endl ;
    cout << "6 - 19CLC4" << endl ;
    cout << "7 - 19CLC5" << endl ;
    cout << "8 - 19CLC6" << endl ;
    cout << "9 - 19CLC7" << endl ;
    cout << "10 - 19CLC8" << endl ;
    cout << "11 - 19CLC9" << endl ;
    cout << "12 - 19CLC10" << endl ;
    cout << "You option : " ;
    cin >> n ;
    while(n != 0 )
    {
        Information person ;
        cout << "Enter ID : " ;
        cin >> person.id ;
        cin.ignore() ;
        cout << "Enter full name : ";
        getline(cin , person.fullname);
        cout << "Enter  year of birth :"<< endl ;
        cin >> person.dob.year ;
        cout << "Enter month of birth : " << endl ;
        cin >> person.dob.month ;
        cout << " Enter date of birth : "<< endl ;
        cin >>person.dob.date ;
        switch (n)
        {
        case 1:
            person.Class = "19APCS1";
            break;
        case 2 :
            person.Class = "19APCS2";
            break ;
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
        add_student_into_file_student_and_flie_class(n , fstu , person , apcs1 , apcs2 , clc1 , clc2 , clc3 , clc4 , clc5 , clc6, clc7 , clc8 , clc9 , clc10 );
        cout << "You option : " ;
        cin >> n ;
    }
}

void remove_a_element_in_file(fstream  &fout , const char* filename , int n , Information* &Person , Information person)
{
    fout.open(filename , ios :: out);
    if(!fout.is_open())
    {
        cout << "Can you not create file "<< endl ;
        fout.close();
        return ;
    }
    else {
    fout << n-1 << endl ;
        for(int i = 0 ; i< n ; i++)
        {
            if(Person[i].id != person.id)
            {
                fout << Person[i].Class << endl ;
                fout << Person[i].id << endl;
                fout << Person[i].dob.year;
                if(Person[i].dob.month < 10 )
                    fout << "0" <<Person[i].dob.month ;
                else
                    fout <<Person[i].dob.month ;
                if(Person[i].dob.date < 10)
                    fout << "0" <<Person[i].dob.date << endl ;
                else
                    fout <<Person[i].dob.date << endl ;
                fout << Person[i].fullname << endl;
                fout << Person[i].dob.year << " ";
                if(Person[i].dob.month < 10 )
                    fout << "0" <<Person[i].dob.month << " ";
                else
                    fout <<Person[i].dob.month << " ";
                if(Person[i].dob.date < 10)
                    fout << "0" <<Person[i].dob.date << endl ;
                else
                    fout <<Person[i].dob.date << endl ;
                fout << endl ;
            }
        }
    }
    fout.close();
}
void remove_element_into_file_student(Information person , fstream &fout)
{
    Information *Person ;
    const char * filename = "Student.txt";
    int n= 0 ;
    load_file(fout , filename ,n , Person);
    remove_a_element_in_file(fout , filename , n , Person , person);
    delete [] Person ;
}
void remove_element_into_file_class (Information person , fstream &fout)
{
    int n = 0 ;
    Information *Person ;

    string temp = "Student_" + person.Class + ".txt";
    const char*filename = temp.c_str();

    load_file(fout , filename , n ,Person ) ;
    remove_a_element_in_file(fout , filename , n , Person , person);
    delete [] Person ;
}
void remove_student_in_file_student_and_flie_class( int n ,fstream &fstu , Information person , fstream &apcs1 , fstream &apcs2 , fstream &clc1 , fstream &clc2 , fstream &clc3 , fstream &clc4 , fstream &clc5 ,fstream &clc6 ,  fstream &clc7 , fstream &clc8 , fstream &clc9 , fstream &clc10)
{
    remove_element_into_file_student(person , fstu);
    switch (n)
    {
    case 1:
    remove_element_into_file_class(person , apcs1);
        break;
    case 2:
    remove_element_into_file_class(person , apcs2);
        break;
    case 3:
    remove_element_into_file_class(person , clc1);
        break;
    case 4:
    remove_element_into_file_class(person , clc2);
        break;
    case 5:
    remove_element_into_file_class(person , clc3);
        break;
    case 6:
    remove_element_into_file_class(person , clc4);
        break;
    case 7:
    remove_element_into_file_class(person , clc5);
        break;
    case 8:
    remove_element_into_file_class(person , clc6);
        break;
    case 9:
    remove_element_into_file_class(person , clc7);
        break;
    case 10:
    remove_element_into_file_class(person , clc8);
        break;
    case 11:
    remove_element_into_file_class(person , clc9);
        break;
    case 12:
    remove_element_into_file_class(person , clc10);
        break;
    default:
        break;
    }
}
void remove_a_student(fstream &fstu , fstream &apcs1 , fstream &apcs2 , fstream &clc1 , fstream &clc2 , fstream &clc3 , fstream &clc4 , fstream &clc5 ,fstream &clc6 ,  fstream &clc7 , fstream &clc8 , fstream &clc9 , fstream &clc10)
{
    int n ;
    cout << "0 - Return" << endl ;
    cout << "1 - 19APCS1" << endl ;
    cout << "2 - 19APCS2" << endl ;
    cout << "3 - 19CLC1" << endl ;
    cout << "4 - 19CLC2" << endl ;
    cout << "5 - 19CLC3" << endl ;
    cout << "6 - 19CLC4" << endl ;
    cout << "7 - 19CLC5" << endl ;
    cout << "8 - 19CLC6" << endl ;
    cout << "9 - 19CLC7" << endl ;
    cout << "10 - 19CLC8" << endl ;
    cout << "11 - 19CLC9" << endl ;
    cout << "12 - 19CLC10" << endl ;
    cout << "You option : " ;
    cin >> n ;
    while(n!= 0)
    {
        Information person ;
        cout << "Enter ID : " ;
        cin >> person.id ;
        switch (n)
        {
        case 1:
            person.Class = "19APCS1";
            break;
        case 2 :
            person.Class = "19APCS2";
            break ;
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
        remove_student_in_file_student_and_flie_class(n  , fstu , person , apcs1 , apcs2 , clc1 , clc2 , clc3 , clc4 ,clc5 ,clc6 ,clc7 ,clc8 ,clc9, clc10);
        cout << "You option : " ;
        cin >> n ;
    }
}