
#include"Manager.h"
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
	
	fstu.seekg(0, SEEK_SET);
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

void manually_add_a_new_student_to_a_class(fstream &fstu , Information person)
{   
    cout << "Enter class : " ; 
    getline(cin , person.Class); 
    cout << "Enter ID : "; 
    getline(cin , person.id); 
    cout << "Enter fullname : ";
    getline(cin , person.fullname); 
    cout << "Enter Year of birth : " ; 
    cin >> person.dob.year ; 
    cout << "Enter month" ; 

    // cout << "0 - 19APCS1" << endl ; 
    // cout << "1 - 19APCS2" << endl ; 
    // cout << "2 - 19CLC1" << endl ;
    // cout << "3 - 19CLC2" << endl ;
    // cout << "4 - 19CLC3" << endl ;
    // cout << "5 - 19CLC4" << endl ;
    // cout << "6 - 19CLC5" << endl ;
    // cout << "7 - 19CLC6" << endl ;
    // cout << "8 - 19CLC7" << endl ;
    // cout << "9 - 19CLC8" << endl ;
    // cout << "10 - 19CLC9" << endl ;
    // cout << "11 - 19CLC10" << endl ;
    // cout << "You option : " ; 
    // cin >> n 

}