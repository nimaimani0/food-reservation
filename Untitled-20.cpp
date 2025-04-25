#include <iostream>
#include <fstream>
using namespace std;

/*  int choice;
wrong:
    cout << "please choose an item :) | register student:1  |  enter student:2  |";
    cin >> choice;
    if (choice == 1)
    {
        ofstream file("students.txt", ios::app);

        register students;
        cout << " please enter student data: " << endl;
        cout << " enter student ID number: ";
        cin >> students.IDnumber;
        cout << "enter student first name: ";
        cin >> students.fname;
        cout << "enter student last name: ";
        cin >> students.lname;
        cout << " enter student phone Number: ";
        cin >> students.phoneNumber;
        cout << "enter student  money: ";
        cin >> students.money;

        file << students.IDnumber << " " << students.fname << " "
             << students.lname << " " << students.phoneNumber << " "
             << students.money << endl;

        file.close();
        cout << "Student has been added" << endl;
        ;
    }

    else if (choice == 2)
    {
        register students;
        fstream("temp.txt", ios::in | ios::out);
        bool found = false;

        while (file >> register.IDnumber)
        {
            if (register.IDnumber == enter)
            {
                found = false;
                cout << " ID number: " << register.IDnumber << endl;
                cout << " first name: " << register.fname << endl;
                cout << "last name: " << register.lname << endl;
                cout << "phone Number: " << register.phoneNumber << endl;
                cout << "money: " << register.money;
            }
            file.close();

            if (found)
            {
                cout << "student not found !";
                goto wrong;
                ّ
            }
        }
    }
}