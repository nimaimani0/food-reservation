/*#include <iostream>
#include <fstream>
using namespace std;
void add_foods();
void read_food();
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
wrong:
    cout << "please choose an item :) | register student:1  |  enter student:2  | register resposible:3|  enter responsible:4 | ";
    cin >> choice;
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
            goto wrong;
        }
    }

    else if (choice == 2)
    {
        Register students;
        fstream File("students.txt", ios::in);
        bool stu = true;
        string enter;
        string enterp;
        cout << "please enter student ID number for search :";
        cin >> enter;
        cout << "please enter student password for search :";
        cin >> enterp;

        while (File >> students.IDnumber >> students.password >> students.fname >> students.lname >> students.phonenumber >> students.money)
        {
            if (students.IDnumber == enter && students.password == enterp)
            {
                bool stu = false;
                cout << "ID number: " << students.IDnumber << endl;
                cout << "password: " << students.password << endl;
                cout << "first name: " << students.fname << endl;
                cout << "last name: " << students.lname << endl;
                cout << "phone Number: " << students.phonenumber << endl;
                cout << "money: " << students.money << endl
                     << endl;
                cout << "portal:" << endl;
            wr:
                cout << "choose an item:" << endl

                     << "1.view dinner/lunch" << endl
                     << "2.reserve food" << endl
                     << "3.cancel reservation" << endl
                     << "4.view reservation" << endl
                     << "5.edit student" << endl
                     << "6.charge student" << endl
                     << "7.exit" << endl;
                int choicee;
                cin >> choicee;
                while (choicee != 7)
                {
                    switch (choicee)
                    {
                    case 1:
                        read_food();
                        break;
                    case 2:

                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                    case 5:
                        break;
                    case 6:
                        break;

                    case 7:
                        exit(0);
                        break;
                    default:
                        cout << "choose a correct item!";
                        goto wr;
                        break;
                    }
                }
            }
        }
        if (stu)
        {
            cout << "student not found !" << endl;
            goto wrong;
        }
        File.close();
    }
    else if (choice == 3)
    {
        cout << "how many responsible do you want add ? ";
        int a;
        cin >> a;
        for (int i = 0; i < a; i++)
        {

            ofstream File("responsible.txt", ios::app);

            Responsible enters;
            cout << "please enter password: ";
            cin >> enters.password;
            cout << "please enter first name :";
            cin >> enters.fname;
            cout << "please enter last name: ";
            cin >> enters.lname;

            File << enters.password << " " << enters.fname << " " << enters.lname << endl;

            File.close();
            cout << "resposible has been added" << endl;
            goto wrong;
        }
    }

    else if (choice == 4)
    {
        Responsible enters;
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
        
    }
    else
    {
        cout << "invalid input!" << endl;
        
    }
}
void add_foods()
{
    ofstream File("foods.txt", ios::app);
    Food foods;
    int a;
    cout << "how many food do you want add? ";
    cin >> a;
    for (int i = 0; i < a; i++)
    {

        cout << "please enter food name:";
        cin >> foods.foodname;
        cout << "please enter food price: (rial)";
        cin >> foods.price;
        cout << "please enter food day: | saterday |sunday| monday| tuesday|wednesday|thursday|friday |";
        cin >> foods.day;
        cout << "please enter that food is for dinner or lunch:";
        cin >> foods.dinnerorlunch;
        cout << "please enter food date : (ex:1403.10.10)";
        cin >> foods.date;
        cout << "please enter food capacity:";
        cin >> foods.capacity;

        File << foods.foodname << " " << foods.price << " " << foods.day << " " << foods.dinnerorlunch << " " << foods.date << " " << foods.capacity << endl;
        cout << "food has been added";
        File.close();
    }
}
void read_food()
{
    ifstream File("foods.txt");
    Food foods;
    while (File >> foods.foodname >> foods.price >> foods.day >> foods.dinnerorlunch >> foods.date >> foods.capacity)
    {
        cout << "food name:" << foods.foodname << "food price: " << foods.price << "food day: " << foods.day << "dinner or lunch: " << foods.dinnerorlunch << "food date: " << foods.date << "food capacity: " << foods.capacity << endl;
    }
    File.close();
}
