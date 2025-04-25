#include <iostream>
#include <fstream>
using namespace std; //nima imani 403103222 proje payani
void add_foods();
void read_food();
void editstudent();
void chargestudent();
void reserve_food();
void cancel();
void view_rese();
void view_stu();
void view_respo();
void delfood_plan();
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
    int price;
    string day;
    string dinnerorlunch;
    string date;
    int capacity;
    string id;
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
    if (choice == 1)
    {
        cout << "how many student do you want add ? ";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {

            ofstream file("studentt.txt", ios::app);

            Register students;
            cout << "please enter student ID number: ";
            cin >> students.IDnumber;
            cout << "please enter a password (just numbers or  just words):";
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
        }
    }

    else if (choice == 2)
    {
        Register students;
        fstream File("studentt.txt", ios::in);
        bool stu = false;
        string enter;
        string enterp;
        cout << "please enter student ID number for search :";
        cin >> enter;
        cout << "please enter student password for search (just numbers or just words):";
        cin >> enterp;

        while (File >> students.IDnumber >> students.password >> students.fname >> students.lname >> students.phonenumber >> students.money)
        {
            if (students.IDnumber == enter && students.password == enterp)
            {
                stu = true;
                cout << "ID number: " << students.IDnumber << endl;
                cout << "password: " << students.password << endl;
                cout << "first name: " << students.fname << endl;
                cout << "last name: " << students.lname << endl;
                cout << "phone Number: " << students.phonenumber << endl;
                cout << "money: " << students.money << endl;
            }
        }
        File.close();
        if (stu)
        {
            cout << "student  found !" << endl;
            cout << "portal:" << endl;
            cout << "choose an item:" << endl

                 << "1.view food plan:" << endl
                 << "2.reserve food" << endl
                 << "3.cancel reservation" << endl
                 << "4.view reservation" << endl
                 << "5.edit student" << endl
                 << "6.charge student " << endl
                 << "7.exit" << endl;

            int choicee;
            cin >> choicee;

            switch (choicee)
            {
            case 1:
                read_food();
                break;
            case 2:
                reserve_food();
                break;
            case 3:
                cancel();
                break;
            case 4:
                view_rese();
                break;
            case 5:
                editstudent();
                break;
            case 6:
                chargestudent();
                break;
            case 7:
                exit(0);
                break;
            default:
                cout << "choose a correct item!";
                break;
            }
        }
        else
        {
            cout << "student not  found !" << endl;
        }
    }
    else if (choice == 3)
    {
        cout << "how many responsible do you want add ? ";
        int a;
        cin >> a;
        for (int i = 0; i < a; i++)
        {

            ofstream File("respo.txt", ios::app);

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
        }
    }

    else if (choice == 4)
    {
        Responsible enters;
        ifstream File("respo.txt");
        bool res = false;
        string enterr;
        string enterrp;

        cout << "please enter responsible password  :(just numbers or just words)";
        cin >> enterr;
        cout << "please enter responsible first name for search :";
        cin >> enterrp;
        while (File >> enters.password >> enters.fname >> enters.lname)
        {
            if (enters.password == enterr && enters.fname == enterrp)
            {
                res = true;
                cout << "password: " << enters.password << endl;
                cout << "first name: " << enters.fname << endl;
                cout << "last name: " << enters.lname << endl;
            }
        }
        if (res)
        {
            cout << "responsible  found !" << endl;
            cout << "chose an item:" << endl
                 << "1.add dinner/lunch food:" << endl
                 << "2.view food plan" << endl
                 << "3.view reservation" << endl
                 << "4.charge student" << endl
                 << "5.edit student :" << endl
                 << "6.view students :" << endl
                 << "7.view responsibles :" << endl
                 << "8.delete food from food plan :" << endl
                 << "9.exit" << endl;
            int chosen;
            cin >> chosen;
            switch (chosen)
            {
            case 1:
                add_foods();
                break;
            case 2:
                read_food();
                break;
            case 3:
                view_rese();
                break;
            case 4:
                chargestudent();
                break;
            case 5:
                editstudent();
                break;
            case 6:
                view_stu();
                break;
            case 7:
                view_respo();
                break;
            case 8:
                delfood_plan();
                break;
            case 9:
                exit(0);
            default:
                cout << "choose a correct item!";

                break;
            }
        }
        else
        {
            cout << "responsible not found !" << endl;
        }
        File.close();
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
        cout << "please enter food ID ";
        cin >> foods.id;

        File << foods.foodname << " " << foods.price << " " << foods.day << " " << foods.dinnerorlunch << " " << foods.date << " " << foods.capacity << " " << foods.id << endl;
    }
    cout << "food has been added" << endl;
    File.close();
}
void read_food()
{
    ifstream File("foods.txt");
    Food foods;
    while (File >> foods.foodname >> foods.price >> foods.day >> foods.dinnerorlunch >> foods.date >> foods.capacity >> foods.id)
    {
        cout << " |food name:" << foods.foodname << " " << "|food price: " << foods.price << " " << "| food day: " << foods.day << " " << "|dinner or lunch: " << foods.dinnerorlunch << " " << "|food date:" << foods.date << " " << "| food capacity:" << foods.capacity << "food Id:" << foods.id << endl;
    }
    File.close();
}
void editstudent()
{
    fstream file("studentt.txt", ios::in | ios::out);
    string editID;
    string pass;
    cout << "please enter student ID that you want to edit:";
    cin >> editID;
    cout << " enter password : ";
    cin >> pass;
    Register students;
    ofstream efile("editt.txt");

    bool stu = false;

    while (file >> students.IDnumber >> students.password >> students.fname >> students.lname >> students.phonenumber >> students.money)
    {
        if (students.IDnumber == editID && students.password == pass)
        {
            stu = true;
            cout << " Name: " << students.fname << endl;
            cout << "new Name: ";
            cin >> students.fname;
            cout << "last name: " << students.lname << endl;
            cout << "new last name: ";
            cin >> students.lname;
            cout << "phone number: " << students.phonenumber << endl;
            cout << "new phone number: ";
            cin >> students.phonenumber;
            cout << "money: " << students.money << endl;
            cout << "new money: ";
            cin >> students.money;
        }
        efile << students.IDnumber << " " << students.password << " " << students.fname << " "
              << students.lname << " " << students.phonenumber << " "
              << students.money << endl;
    }

    file.close();
    efile.close();
    remove("studentt.txt");
    rename("editt.txt", "studentt.txt");
    if (stu)
    {
        cout << "Student edited " << endl;
    }
    else
    {
        cout << "student not found!" << endl;
    }
}
void chargestudent()
{
    fstream file("studentt.txt", ios::in | ios::out);

    string editID;
    string pass;
    int charge;
    cout << "please enter student ID number: ";
    cin >> editID;
    cout << "please enter password:";
    cin >> pass;
    cout << "please enter new money to add: ";
    cin >> charge;
    Register students;
    ofstream File("editt.txt");
    bool stu = false;
    while (file >> students.IDnumber >> students.password >> students.fname >> students.lname >> students.phonenumber >> students.money)
    {
        if (students.IDnumber == editID && students.password == pass)
        {
            stu = true;
            int chargee;
            chargee = students.money;

            students.money = (charge + chargee);
        }
        File << students.IDnumber << " " << students.password << " " << students.fname << " "
             << students.lname << " " << students.phonenumber << " "
             << students.money << endl;
    }

    file.close();
    File.close();
    remove("studentt.txt");
    rename("editt.txt", "studentt.txt");

    if (stu = true)
    {
        cout << "student charged " << endl;
    }
    else if (stu = false)
    {
        cout << "student not found!" << endl;
    }
}
void reserve_food()
{
    ifstream food("foods.txt");
    ifstream student("studentt.txt");
    ofstream foodfile("foodfile.txt");
    ofstream studentfile("studentfile.txt");
    ofstream reservation("reservationn.txt", ios::app);

    string foodname, IDnumber, id;
    cout << "please enter food name for reserving: ";
    cin >> foodname;
    cout << "please enter food ID : ";
    cin >> id;
    cout << "please enter student ID number : ";
    cin >> IDnumber;
    Food foods;
    Register students;
    bool fo = false;
    bool st = false;
    bool rese = false;

    while (food >> foods.foodname >> foods.price >> foods.day >> foods.dinnerorlunch >> foods.date >> foods.capacity >> foods.id)
    {
        if (foods.id == id && foods.capacity > 0)
        {
            fo = true;
            foods.capacity -= 1;

            while (student >> students.IDnumber >> students.password >> students.fname >> students.lname >> students.phonenumber >> students.money)
            {
                if (students.IDnumber == IDnumber)
                {
                    st = true;
                    if (students.money >= foods.price)
                    {
                        students.money -= foods.price;
                        reservation << students.IDnumber << " " << students.password << " " << foods.foodname << " "
                                    << foods.price << " " << foods.day << " "
                                    << foods.dinnerorlunch << " " << foods.date << " " << foods.capacity << " " << foods.id << endl;
                        rese = true;
                    }
                }
                studentfile << students.IDnumber << " " << students.password << " " << students.fname << " "
                            << students.lname << " " << students.phonenumber << " "
                            << students.money << endl;
            }
        }
        foodfile << foods.foodname << " " << foods.price << " " << foods.day << " " << foods.dinnerorlunch << " "
                 << foods.date << " " << foods.capacity << " " << foods.id << endl;
    }
    food.close();
    student.close();
    foodfile.close();
    studentfile.close();
    reservation.close();

    remove("foods.txt");
    rename("foodfile.txt", "foods.txt");
    remove("studentt.txt");
    rename("studentfile.txt", "studentt.txt");

    if (!fo)
    {
        cout << "food not found " << endl;
    }
    if (!st)
    {
        cout << "Student not found" << endl;
    }
    if (rese)
    {
        cout << "reserved" << endl;
    }
    else if (fo && st)
    {
        cout << "Reservation failed due to insufficient balance" << endl;
    }
}
void cancel()
{

    ifstream reservation("reservationn.txt");
    ifstream food("foods.txt");
    ifstream student("studentt.txt");
    ofstream reservationfile("reservationnfile.txt");
    ofstream foodfile("foodfile.txt");
    ofstream studentfile("studentfile.txt");
    string IDnumber;
    string foodname;
    string id;
    cout << "please enter ID number to cancel reservation: ";
    cin >> IDnumber;
    cout << "please enter food name to cancel reservation: ";
    cin >> foodname;
    cout << "please enter food ID :";
    cin >> id;

    bool rese = false;
    bool fo = false;
    bool stu = false;
    Food foods;
    Register students;
    while (food >> foods.foodname >> foods.price >> foods.day >> foods.dinnerorlunch >> foods.date >> foods.capacity >> foods.id)
    {
        if (foods.foodname == foodname && foods.id == id)
        {
            foods.capacity += 1;
            fo = true;

            while (student >> students.IDnumber >> students.password >> students.fname >> students.lname >> students.phonenumber >> students.money)
            {
                if (students.IDnumber == IDnumber)
                {
                    students.money += foods.price;
                    stu = true;
                }
                studentfile << students.IDnumber << " " << students.password << " " << students.fname << " "
                            << students.lname << " " << students.phonenumber << " "
                            << students.money << endl;
            }
        }
        foodfile << foods.foodname << " " << foods.price << " "
                 << foods.day << " " << foods.dinnerorlunch << " "
                 << foods.date << " " << foods.capacity << " " << foods.id << endl;
    }
    if (stu == true && fo == true)
    {
        while (food >> foods.foodname >> foods.price >> foods.day >> foods.dinnerorlunch >> foods.date >> foods.capacity >> foods.id)
        {
            if (foods.foodname == foodname && foods.id == id)
            {
                continue;
            }
            foodfile << foods.foodname << " " << foods.price << " "
                     << foods.day << " " << foods.dinnerorlunch << " "
                     << foods.date << " " << foods.capacity << " " << foods.id << endl;
        }
    }
    food.close();
    student.close();
    reservation.close();
    foodfile.close();
    studentfile.close();
    reservationfile.close();
    remove("foods.txt");
    rename("foodfile.txt", "foods.txt");
    remove("studentt.txt");
    rename("studentfile.txt", "studentt.txt");
    remove("reservationn.txt");
    rename("reservationnfile.txt", "reservationn.txt");
    if (fo == false)
    {
        cout << "food doesnt found" << endl;
    }
    if (stu == false)
    {
        cout << "student doesnt found" << endl;
    }

    else
    {
        cout << "cancelled" << endl
             << "pay more attention in your next choices!" << endl;
    }
}
void view_rese()
{
    ifstream rese("reservationn.txt");

    string reserve;
    cout << "reservations are :" << endl;
    while (getline(rese, reserve))
    {
        cout << reserve << endl;
    }

    rese.close();
}
void view_stu()
{
    ifstream stu("studentt.txt");
    string stud;
    cout << "students are:" << endl;
    while (getline(stu, stud))
    {
        cout << stud << endl;
    }
    stu.close();
}
void view_respo()
{
    ifstream respo("respo.txt");
    string resp;
    cout << "responsibles are " << endl;
    while (getline(respo, resp))
    {

        cout << resp << endl;
    }

    respo.close();
}
void delfood_plan()
{
    ifstream foodplan("foods.txt");
    ofstream foodfile("foodfile.txt");
    Food foods;
    string foodname;
    string id;
    cout << "please enter food name :" << endl;
    cin >> foodname;
    cout << "please enter food ID :" << endl;
    cin >> id;
    bool yes=false;
    while (foodplan >> foods.foodname >> foods.price >> foods.day >> foods.dinnerorlunch >> foods.date >> foods.capacity >> foods.id)
    {
        if (foods.foodname == foodname && foods.id == id)
        {   yes=true;
            continue;
        }
        foodfile << foods.foodname << " " << foods.price << " "
                 << foods.day << " " << foods.dinnerorlunch << " "
                 << foods.date << " " << foods.capacity << " " << foods.id << endl;
    }

    foodplan.close();
    foodfile.close();
    remove("foods.txt");
    rename("foodfile.txt", "foods.txt");
    if(true){
     cout<<"deleted!";



    }
}