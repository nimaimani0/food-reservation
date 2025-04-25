/*#include <iostream>
#include <fstream>
using namespace std;
void add_foods();
void read_food();
void student();
void responsible()
struct Register
{
    string password;
    string IDnumber;
    string fname;
    string lname;
    string phonenumber;
    int money;
};
struct Food
{
    string foodname;
    string price;
    string day;
    string dinnerorlunch;
    string date;
    int capacity;
};
struct Responsible
{
    string password;
    string fname;
    string lname;
};
int main()
{
    int choice;
    cout << "please choose an item :) | register student:1  |  enter student:2  | register resposible:3|  enter responsible:4 | ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        student();
        break;
        case 2:student();
        break;
        case 3:responsible();
        break;
        case 4:responsible();
        break;
    
    default:
        break;
    }
    
    void student(int choice){

if (choice == 1)
    {
        cout << "how many student do you want add ? ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {

            ofstream file("students.txt", ios::app);

            Register students;
            cout << "please enter student ID number: ";
            cin >> students.IDnumber;
            cout << "please enter a password :";
            cin >> students.password;
            cout << "please enter student first name: ";
            cin >> students.fname;
            cout << "please enter student last name: ";
            cin >> students.lname;
            cout << "please enter student phone Number: ";
            cin >> students.phonenumber;
            cout << "please enter student  money: ";
            cin >> students.money;

            file << students.IDnumber << " " << students.password << " " << students.fname << " "
                 << students.lname << " " << students.phonenumber << " "
                 << students.money << endl;

            file.close();
            cout << "Student has been added" << endl;
            ;
        }
    }





    }
    
    
    
    void responsible(){






    }
    
    
    }
/*Responsible enters;
        ifstream Filee("resposible.txt");
        bool res = true;
        string enterr;
        string enterrp;
    
        cout << "please enter responsible password :";
        cin >> enterr;
        cout << "please enter responsible first name for search :";
        cin >> enterrp;
        while (Filee >> enters.password >> enters.fname >> enters.lname)
        {
            if (enters.password == enterr && enters.fname == enterrp)
            {
                bool res = false;
                cout << "password: " << enters.password << endl;
                cout << "first name: " << enters.fname << endl;
                cout << "last name: " << enters.lname << endl;
                cout << "chose an item:" << endl
                     << "1.add dinner/lunch food:" << endl
                     << "2.view reservation" << endl
                     << "3.edit student" << endl
                     << "4.charge student" << endl;
                int chosen;
                cin >> chosen;
                switch (chosen)
                {
                case 1:
                    add_foods();
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    cout << "choose a correct item!";
                
                    break;
                }
            }
            if (res)
            {
                cout << "responsible not found !" << endl;
                
            }
           
        }
         Filee.close();
    }
    else
    {
        cout << "invalid input!" << endl;
        
    }/////
 fstream file("studentt.txt", ios::in | ios::out);
    
    string editID;
    string pass;
    int charge;
    cout << "please enter student ID number: ";
    cin >> editID;
    cout<<"please enter password:";
    cin>>pass;
    cout << "please enter new money to add: ";
    cin >> charge;
    Register students;
    ofstream File("editt.txt");
    bool stu = false;
    while (file >> students.IDnumber >> students.password >> students.fname >> students.lname >> students.phonenumber >> students.money)
    {
        if (students.IDnumber == editID && students.password==pass)
        {    stu = true;

            students.money += charge;
           
        }
        File << students.IDnumber << " " << students.password << " " << students.fname << " "
             << students.lname << " " << students.phonenumber << " "
             << students.money << endl;
    }

    file.close();
    File.close();
    remove("studentt.txt");
    rename("editt.txt", "studentt.txt");