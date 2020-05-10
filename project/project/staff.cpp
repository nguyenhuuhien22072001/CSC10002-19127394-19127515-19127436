
#include "Manager.h"

void load_file( const char * filename , int &n ,  Information* &Person )
{
    fstream fin ;
    fin.open(filename , ios :: in );
    if(!fin.is_open())
    {
        cout << "           Can you not create file "<< endl ;
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

void Importstudents()//filename= "student_"
{
    int num1 ;
    cout << "0 - Return" << endl ;
    cout << "1 - Import students" << endl ;
    cout << "You option : " ;
    cin >> num1 ;
    while(num1 != 0 )
    {
        cin.ignore();
        string classname;
        cout << "   Enter Classname:";
        getline(cin, classname);

        Information student[100];
        int n = 0;

        ifstream fcsv;
        
        string temp = "Student_" + classname + ".csv";
        const char* inputfilename = temp.c_str();
        
        fcsv.open(inputfilename);
        if (!fcsv.is_open())
        {
            cout << "   Import fail"<< endl;
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
            getline(fcsv, student[n].id,',');
            getline(fcsv, student[n].fullname, ',');
            fcsv>>student[n].dob.year;
            fcsv >> c;
            fcsv>>student[n].dob.month;
            fcsv >> c;
            fcsv>>student[n].dob.date;
            fcsv >> c;
            getline(fcsv, student[n].Class, '\n');
            string date ;
            string month ;
            if(student[n].dob.month < 10)
                month = "0" + to_string(student[n].dob.month);
            else
                month = to_string(student[n].dob.month);
            if(student[n].dob.date < 10 )
                date =  "0" + to_string(student[n].dob.date);
            else
                date = to_string(student[n].dob.date) ;
            student[n].password = to_string(student[n].dob.year) + month + date;
            student[n].type = 2;
            n++;
        }
        
        saveStudent(student, classname,n-1);
        fcsv.close();
        
        cout << "You option : " ;
        cin >> num1;
    }
}

void saveStudent(Information* student, string classname, int n)
{
    fstream f;
    string temp_1 = "Student_" + classname + ".txt";
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
        if(student[i].dob.date < 10)
            f<< "0" << student[i].dob.date << endl;
        else
            f<< student[i].dob.date << endl  ;
        f << student[i].fullname << endl;
        f << student[i].dob.year<< " ";
        if(student[i].dob.month < 10)
            f <<"0" <<  student[i].dob.month << " ";
        else
            f << student[i].dob.month << " ";
        if(student[i].dob.date < 10)
            f << "0" << student[i].dob.date<< endl << endl;
        else
            f << student[i].dob.date<< endl << endl;
    }
    f.close();
}

void edit_student()
{
    int num1 ;
    Information* student ;
    cout << "0 - Return"<< endl ;
    cout << "1 - Edit student "<< endl ;
    cout << "You choice : "  ;
    cin >> num1 ;
    while(num1 != 0)
    {
        int n = 0;
        string classname;
        string username ;
        cin.ignore();
        cout << "   Enter class: ";
        getline(cin, classname);
        cout << "   Enter username(ID): ";
        getline(cin, username);
        string temp_1 = "Student_" + classname + ".txt";
        const char* filename = temp_1.c_str();
        load_file(filename, n, student);
        for (int i = 0; i < n; i++)
        {
            if (username == student[i].id)
            {
                int num2 ;
                cout << "   Edit student : "<< endl ;
                cout << "   0. Return."<< endl ;
                cout << "   1. Edit id." << endl;
                cout << "   2. Edit name." << endl;
                cout << "   3. Edit dob." << endl;
                cout << "   Your choice: ";
                cin >> num2 ;
                while(num2 != 0)
                {
                    switch (num2)
                    {
                        case 1:
                        {
                            cout << "       Enter new id: ";
                            cin.ignore();
                            getline(cin, student[i].id);
                            break ;
                        }
                        case 2:
                        {
                            cout << "       Enter new name: ";
                            cin.ignore();
                            getline(cin, student[i].fullname);
                            break ;
                        }
                        case 3:
                        {
                            cout << "       Enter new year: ";
                            cin >> student[i].dob.year;
                            cout << "       Enter new month: ";
                            cin >> student[i].dob.month;
                            cout << "       Enter new date: ";
                            cin >> student[i].dob.date;
                            break ;
                        }
                        default:
                            break ;
                    }
                    cout <<"   Your choice:";
                    cin >> num2 ;
                }
            }
        }
        saveStudent(student, classname, n);
        delete [] student;
        cout <<"Your choice: ";
        cin >> num1 ;
    }
}

void add_a_element_in_file( const char * filename ,  int n , Information* &Person , Information person)
{
    fstream fout ;
    fout.open(filename  , ios:: out);
    if(!fout.is_open())
    {
        cout << "           Can you not create file "<< endl ;
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
                fout << Person[i].dob.month << " ";
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

void remove_a_element_in_file(const char* filename , int n , Information* &Person , Information person)
{
    fstream fout ;
    fout.open(filename , ios :: out);
    if(!fout.is_open())
    {
        cout << "           Can you not create file "<< endl ;
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

void add_student_into_file_student_and_flie_class(Information person)
{
    int n = 0 ;
    Information *Person ;
    const char * filename_student ="Student.txt";
    load_file(filename_student , n ,Person ) ;
    add_a_element_in_file(filename_student , n , Person , person);
    delete [] Person ;
    
    string filename_class = "Student_" + person.Class + ".txt";
    const char*filename = filename_class.c_str();
    load_file( filename , n ,Person ) ;
    add_a_element_in_file(filename , n , Person , person);
    delete [] Person ;
}

void manually_add_a_new_student_to_a_class()
{
    int num ;
    cout << "0 - Return" << endl ;
    cout << "1 - add student"<< endl ;
    cout << "You option : " ;
    cin >> num ;
    while(num != 0 )
    {
        int n ;
        cout << "   0 - Return" << endl ;
        cout << "   1 - 19APCS1" << endl ;
        cout << "   2 - 19APCS2" << endl ;
        cout << "   3 - 19CLC1" << endl ;
        cout << "   4 - 19CLC2" << endl ;
        cout << "   5 - 19CLC3" << endl ;
        cout << "   6 - 19CLC4" << endl ;
        cout << "   7 - 19CLC5" << endl ;
        cout << "   8 - 19CLC6" << endl ;
        cout << "   9 - 19CLC7" << endl ;
        cout << "   10 - 19CLC8" << endl ;
        cout << "   11 - 19CLC9" << endl ;
        cout << "   12 - 19CLC10" << endl ;
        cout << "   You option : " ;
        cin >> n ;
        while(n != 0 )
        {
            Information person ;
            cout << "       Enter ID : " ;
            cin >> person.id ;
            cin.ignore() ;
            cout << "       Enter full name : ";
            getline(cin , person.fullname);
            cout << "       Enter  year of birth :";
            cin >> person.dob.year ;
            cout << "       Enter month of birth : "  ;
            cin >> person.dob.month ;
            cout << "       Enter date of birth : " ;
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
            add_student_into_file_student_and_flie_class(person);
            cout << "   You option : " ;
            cin >> n ;
        }
        cout << "You option : " ;
        cin >> num ;
    }
}

void remove_student_in_file_student_and_flie_class(  Information person)
{
    int n= 0 ;
    Information *Person ;
    const char * filename_student = "Student.txt";
    load_file( filename_student ,n , Person);
    remove_a_element_in_file(filename_student , n , Person , person);
    delete [] Person ;
    
    string filename_class = "Student_" + person.Class + ".txt";
    const char*filename = filename_class.c_str();

    load_file( filename , n ,Person ) ;
    remove_a_element_in_file(filename , n , Person , person);
    delete [] Person ;
    
}

void remove_a_student()
{
    int num ;
    cout << "0 - Return"<< endl ;
    cout << "1 - Remove student" << endl ;
    cout << "You option : " ;
    cin >> num;
    while(num != 0)
    {
        int n ;
        cout << "   Remove student : " << endl ;
        cout << "   0 - Return" << endl ;
        cout << "   1 - 19APCS1" << endl ;
        cout << "   2 - 19APCS2" << endl ;
        cout << "   3 - 19CLC1" << endl ;
        cout << "   4 - 19CLC2" << endl ;
        cout << "   5 - 19CLC3" << endl ;
        cout << "   6 - 19CLC4" << endl ;
        cout << "   7 - 19CLC5" << endl ;
        cout << "   8 - 19CLC6" << endl ;
        cout << "   9 - 19CLC7" << endl ;
        cout << "   10 - 19CLC8" << endl ;
        cout << "   11 - 19CLC9" << endl ;
        cout << "   12 - 19CLC10" << endl ;
        cout << "   You option : " ;
        cin >> n ;
        while(n!= 0)
        {
            Information person ;
            cout << "       Enter ID : " ;
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
            remove_student_in_file_student_and_flie_class(person);
            cout << "   You option : " ;
            cin >> n ;
        }
        cout << "You option : " ;
        cin >> num ;
    }
}
