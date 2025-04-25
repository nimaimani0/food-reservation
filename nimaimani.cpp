#include <iostream>    //nima imani 403103222 lastproject /linkedlist /reservation
#include <fstream>
#include <ostream>
#include <limits>
using namespace std;

struct Register
{
    string password;
    string IDnumber;
    string fname;
    string lname;
    string phonenumber;
    int money;
    Register *next;
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
    Food *next;
};

struct Responsible
{
    string password;
    string fname;
    string lname;
    Responsible *next;
};

struct Reservation
{
    string foodname;
    string day;
    string dinnerorlunch;
    string date;
    string id;
    string IDnumber;
    string password;
    int price;
    int capacity;
    Reservation *next;
};

Register *student_head = NULL;
Food *food_head = NULL;
Responsible *respo_head = NULL;
Reservation *reservation_head = NULL;

void enter_responsible();
void add_responsible();
void add_student();
void enter_student();
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
void edit_food();
void save_students_to_file();
void save_foods_to_file();
void save_respos_to_file();
void save_reservations_to_file();
void load_students_from_file();
void load_foods_from_file();
void load_respos_from_file();
void load_reservations_from_file();

int main()
{
    load_students_from_file();
    load_foods_from_file();
    load_respos_from_file();
    load_reservations_from_file();

    int choice;
    while (true)
    {
        cout << "please choose an item :)" << endl
             << "| register student:1" << endl
             << "| enter student:2" << endl
             << "| register responsible:3" << endl
             << "| enter responsible:4" << endl
             << "| exit:0" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            enter_student();
            break;
        case 3:
            add_responsible();
            break;
        case 4:
            enter_responsible();
            break;
        case 0:
            save_students_to_file();
            save_foods_to_file();
            save_respos_to_file();
            save_reservations_to_file();
            exit(0);
        default:
            cout << "invalid input!" << endl;
        }
    }
}

void save_students_to_file()
{
    ofstream file("studentt.txt");
    Register *current = student_head;
    while (current != NULL)
    {
        file << current->IDnumber << " " << current->password << " "
             << current->fname << " " << current->lname << " "
             << current->phonenumber << " " << current->money << endl;
        current = current->next;
    }
    file.close();
}

void save_foods_to_file()
{
    ofstream file("foods.txt");
    Food *current = food_head;
    while (current != NULL)
    {
        file << current->foodname << " " << current->price << " "
             << current->day << " " << current->dinnerorlunch << " "
             << current->date << " " << current->capacity << " " << current->id << endl;
        current = current->next;
    }
    file.close();
}

void save_respos_to_file()
{
    ofstream file("respo.txt");
    Responsible *current = respo_head;
    while (current != NULL)
    {
        file << current->password << " " << current->fname << " " << current->lname << endl;
        current = current->next;
    }
    file.close();
}

void save_reservations_to_file()
{
    ofstream file("reservationn.txt");
    Reservation *current = reservation_head;

    while (current != NULL)
    {
        file << current->IDnumber << " " << current->password << " "
             << current->foodname << " " << current->price << " "
             << current->day << " " << current->dinnerorlunch << " "
             << current->date << " " << current->capacity << " " << current->id << endl;
        current = current->next;
    }
    file.close();
}

void load_students_from_file()
{
    ifstream file("studentt.txt");
    if (!file)
        return;

    Register temp;
    while (file >> temp.IDnumber >> temp.password >> temp.fname >> temp.lname >> temp.phonenumber >> temp.money)
    {
        Register *new_student = new Register(temp);
        new_student->next = student_head;
        student_head = new_student;
    }
    file.close();
}

void load_foods_from_file()
{
    ifstream file("foods.txt");
    if (!file)
        return;

    Food temp;
    while (file >> temp.foodname >> temp.price >> temp.day >> temp.dinnerorlunch >> temp.date >> temp.capacity >> temp.id)
    {
        Food *new_food = new Food(temp);
        new_food->next = food_head;
        food_head = new_food;
    }
    file.close();
}

void load_respos_from_file()
{
    ifstream file("respo.txt");
    if (!file)
        return;

    Responsible temp;
    while (file >> temp.password >> temp.fname >> temp.lname)
    {
        Responsible *new_respo = new Responsible(temp);
        new_respo->next = respo_head;
        respo_head = new_respo;
    }
    file.close();
}

void load_reservations_from_file()
{
    ifstream file("reservationn.txt");
    if (!file)
        return;

    Reservation temp;
    while (file >> temp.IDnumber >> temp.password >> temp.foodname >> temp.price >> temp.day >> temp.dinnerorlunch >> temp.date >> temp.capacity >> temp.id)
    {
        Reservation *new_res = new Reservation(temp);
        new_res->next = reservation_head;
        reservation_head = new_res;
    }
    file.close();
}

void export_student_reservations()
{
    string studentID;
    cout << "Enter the student ID: ";
    cin >> studentID;

    ofstream File("student_" + studentID + ".txt");

    Reservation *temp = reservation_head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->IDnumber == studentID)
        {
            cout << "food name: " << temp->foodname << endl
                 << "day: " << temp->day << endl
                 << "dinner or lunch: " << temp->dinnerorlunch << endl
                 << "date: " << temp->date << endl
                 << "reservation ID: " << temp->id << endl
                 << "price: " << temp->price << endl
                 << "--------------------------" << endl;
            File << "food name: " << temp->foodname << endl;
            File << "day: " << temp->day << endl;
            File << "dinner or lunch: " << temp->dinnerorlunch << endl;
            File << "date: " << temp->date << endl;
            File << "reservation ID: " << temp->id << endl;
            File << "price: " << temp->price << endl;
            File << "--------------------------" << endl;
            found = true;
        }
        temp = temp->next;
    }

    File.close();

    if (found)
    {
        cout << "reservations for student ID " << studentID << " saved to file successfully." << endl;
    }
    else
    {
        cout << "no reservations found for student ID " << studentID << "." << endl;
    }
}

void add_responsible()
{
    cout << "how many responsible do you want add? ";
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        Responsible *new_respo = new Responsible;
        cout << "please enter password: ";
        cin >> new_respo->password;
        cout << "please enter first name: ";
        cin >> new_respo->fname;
        cout << "please enter last name: ";
        cin >> new_respo->lname;

        new_respo->next = respo_head;
        respo_head = new_respo;

        cout << "responsible has been added" << endl;
    }
}
void enter_responsible()
{
    string enterPw, enterName;
    cout << "please enter responsible password: ";
    cin >> enterPw;
    cout << "please enter responsible first name for search: ";
    cin >> enterName;

    Responsible *current = respo_head;
    bool found = false;
    while (current != nullptr)
    {
        if (current->password == enterPw && current->fname == enterName)
        {
            found = true;
            cout << "password: " << current->password << endl;
            cout << "first name: " << current->fname << endl;
            cout << "last name: " << current->lname << endl;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "responsible not found!" << endl;
        return;
    }

    int subb = -1;
    cout << "responsible found!" << endl;
    while (subb != 11)
    {
        cout << "choose an item:" << endl
             << "1. add dinner/lunch food" << endl
             << "2. view food plan" << endl
             << "3. view reservation" << endl
             << "4. charge student" << endl
             << "5. edit student" << endl
             << "6. view students" << endl
             << "7. view responsibles" << endl
             << "8. delete food from plan" << endl
             << "9. edit food plan" << endl
             << "10. export student reservations" << endl
             << "11. exit" << endl;

        cin >> subb;

        switch (subb)
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
            edit_food();
            break;
        case 10:
            export_student_reservations();
            break;
        case 11:
            return;
            break;
        default:
            cout << "choose a correct item!" << endl;
            break;
        }
    }
}

void add_student()
{
    cout << "how many student do you want add ? ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Register *new_student = new Register;
        cout << "please enter student ID number: ";
        cin >> new_student->IDnumber;
        cout << "please enter a password: ";
        cin >> new_student->password;
        cout << "please enter student first name: ";
        cin >> new_student->fname;
        cout << "please enter student last name: ";
        cin >> new_student->lname;
        cout << "please enter student phone number: ";
        cin >> new_student->phonenumber;
        cout << "please enter student money: ";
        cin >> new_student->money;

        new_student->next = student_head;
        student_head = new_student;

        cout << "Student has been added" << endl;
    }
}

void enter_student()
{
    string enterId, enterPass;
    cout << "please enter student ID number for search: ";
    cin >> enterId;
    cout << "please enter student password for search: ";
    cin >> enterPass;

    Register *current = student_head;
    bool found = false;
    while (current != NULL)
    {
        if (current->IDnumber == enterId && current->password == enterPass)
        {
            found = true;
            cout << "ID number: " << current->IDnumber << endl;
            cout << "password: " << current->password << endl;
            cout << "first name: " << current->fname << endl;
            cout << "last name: " << current->lname << endl;
            cout << "phone number: " << current->phonenumber << endl;
            cout << "money: " << current->money << endl;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "student not found!" << endl;
        return;
    }

    cout << "student found!" << endl;
    int sub = 0;
    while (sub != 8)
    {
        cout << "portal:" << endl;
        cout << "choose an item:" << endl
             << "1. view food plan" << endl
             << "2. reserve food" << endl
             << "3. cancel reservation" << endl
             << "4. export my reservations " << endl
             << "5. edit student" << endl
             << "6. charge student" << endl
             << "7. exit" << endl;

        cin >> sub;

        switch (sub)
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
            export_student_reservations();
            break;
        case 5:
            editstudent();
            break;
        case 6:
            chargestudent();
            break;
        case 7:
            return;
            break;

        default:
            cout << "choose a correct item!" << endl;
            break;
        }
    }
}

void add_foods()
{
    cout << "how many food do you want add? ";
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        Food *new_food = new Food;
        cout << "please enter food name:";
        cin >> new_food->foodname;
        cout << "please enter food price: (rial)";
        cin >> new_food->price;
        cout << "please enter food day: | saterday |sunday| monday| tuesday|wednesday|thursday|friday |";
        cin >> new_food->day;
        cout << "please enter that food is for dinner or lunch:";
        cin >> new_food->dinnerorlunch;
        cout << "please enter food date : (ex:1403.10.10)";
        cin >> new_food->date;
        cout << "please enter food capacity:";
        cin >> new_food->capacity;
        cout << "please enter food ID ";
        cin >> new_food->id;

        new_food->next = food_head;
        food_head = new_food;

        cout << "food has been added" << endl;
    }
}

void read_food()
{
    Food *current = food_head;
    while (current != NULL)
    {
        cout << " |food name:" << current->foodname << " "
             << "|food price: " << current->price << " "
             << "| food day: " << current->day << " "
             << "|dinner or lunch: " << current->dinnerorlunch << " "
             << "|food date:" << current->date << " "
             << "| food capacity:" << current->capacity
             << "|food Id:" << current->id << endl;
        current = current->next;
    }
}

void editstudent()
{
    string editID, pass;
    cout << "please enter student ID that you want to edit:";
    cin >> editID;
    cout << " enter password : ";
    cin >> pass;

    Register *current = student_head;
    bool stu = false;
    while (current != NULL)
    {
        if (current->IDnumber == editID && current->password == pass)
        {
            stu = true;
            cout << "name: " << current->fname << endl;
            cout << "new Name: ";
            cin >> current->fname;
            cout << "last name: " << current->lname << endl;
            cout << "new last name: ";
            cin >> current->lname;
            cout << "phone number: " << current->phonenumber << endl;
            cout << "new phone number: ";
            cin >> current->phonenumber;
            cout << "money: " << current->money << endl;
            cout << "new money: ";
            cin >> current->money;
            break;
        }
        current = current->next;
    }

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
    string editID, pass;
    int charge;
    cout << "please enter student ID number: ";
    cin >> editID;
    cout << "please enter password:";
    cin >> pass;
    cout << "please enter new money to add: ";
    cin >> charge;

    Register *current = student_head;
    bool stu = false;
    while (current != NULL)
    {
        if (current->IDnumber == editID && current->password == pass)
        {
            stu = true;
            current->money += charge;
            break;
        }
        current = current->next;
    }

    if (stu)
    {
        cout << "student charged " << endl;
    }
    else
    {
        cout << "student not found!" << endl;
    }
}

void reserve_food()
{
    string foodname, IDnumber, id;
    cout << "please enter food name for reserving: ";
    cin >> foodname;
    cout << "please enter food ID : ";
    cin >> id;
    cout << "please enter student ID number : ";
    cin >> IDnumber;

    bool fo = false, st = false, rese = false;
    Food *food_current = food_head;
    while (food_current != NULL)
    {
        if (food_current->id == id && food_current->capacity > 0)
        {
            fo = true;
            Register *student_current = student_head;
            while (student_current != NULL)
            {
                if (student_current->IDnumber == IDnumber)
                {
                    st = true;
                    if (student_current->money >= food_current->price)
                    {
                        student_current->money -= food_current->price;
                        food_current->capacity -= 1;
                        rese = true;

                        ofstream reservation("reservationn.txt", ios::app);
                        reservation << student_current->IDnumber << " " << student_current->password << " "
                                    << food_current->foodname << " " << food_current->price << " "
                                    << food_current->day << " " << food_current->dinnerorlunch << " "
                                    << food_current->date << " " << food_current->capacity << " "
                                    << food_current->id << endl;
                        reservation.close();
                        break;
                    }
                }
                student_current = student_current->next;
            }
            if (rese)
                break;
        }
        food_current = food_current->next;
    }

    if (!fo)
        cout << "food not found " << endl;
    if (!st)
        cout << "student not found" << endl;
    if (rese)
        cout << "reserved" << endl;
    else if (fo && st)
        cout << "you have no account balance!" << endl;
}

void cancel()
{
    string IDnumber, foodname, id;
    cout << "please enter ID number to cancel reservation: ";
    cin >> IDnumber;
    cout << "please enter food name to cancel reservation: ";
    cin >> foodname;
    cout << "please enter food ID :";
    cin >> id;

    bool fo = false, stu = false;
    Food *food_current = food_head;
    while (food_current != NULL)
    {
        if (food_current->foodname == foodname && food_current->id == id)
        {
            fo = true;
            Register *student_current = student_head;
            while (student_current != NULL)
            {
                if (student_current->IDnumber == IDnumber)
                {
                    stu = true;
                    student_current->money += food_current->price;
                    food_current->capacity += 1;

                    break;
                }
                student_current = student_current->next;
            }
            if (stu)
                break;
        }
        food_current = food_current->next;
    }

    if (!fo)
        cout << "food doesnt found" << endl;
    if (!stu)
        cout << "student doesnt found" << endl;
    else
        cout << "cancelled" << endl
             << "pay more attention in your next choices!" << endl;
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
    Register *current = student_head;
    cout << "students are:" << endl;
    while (current != NULL)
    {
        cout << current->IDnumber << " " << current->password << " "
             << current->fname << " " << current->lname << " "
             << current->phonenumber << " " << current->money << endl;
        current = current->next;
    }
}

void view_respo()
{
    Responsible *current = respo_head;
    cout << "responsibles are " << endl;
    while (current != NULL)
    {
        cout << current->password << " " << current->fname << " " << current->lname << endl;
        current = current->next;
    }
}

void delfood_plan()
{
    string foodname, id;
    cout << "please enter food name :" << endl;
    cin >> foodname;
    cout << "please enter food ID :" << endl;
    cin >> id;

    Food *current = food_head;
    Food *prev = NULL;
    bool yes = false;

    while (current != NULL)
    {
        if (current->foodname == foodname && current->id == id)
        {
            yes = true;
            if (prev == NULL)
            {
                food_head = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }

    if (yes)
    {
        cout << "deleted!" << endl;
    }
    else
    {
        cout << "food not found!" << endl;
    }
}

void edit_food()
{
    string editfood, foodID;
    cout << "please enter food name that you want to edit:";
    cin >> editfood;
    cout << " enter food ID : ";
    cin >> foodID;

    Food *current = food_head;
    bool fo = false;
    while (current != NULL)
    {
        if (current->foodname == editfood && current->id == foodID)
        {
            fo = true;
            cout << "price :  " << current->price << endl;
            cout << "new food price : ";
            cin >> current->price;
            cout << "capacity : " << current->capacity << endl;
            cout << "new food capacity : ";
            cin >> current->capacity;
            break;
        }
        current = current->next;
    }

    if (fo)
    {
        cout << "food edited " << endl;
    }
    else
    {
        cout << "food not found!" << endl;
    }
}
