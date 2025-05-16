#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <string>
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
Register* Registerhead = NULL;
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
Food* Foodhead =NULL;
struct Responsible
{
    string password;
    string fname;
    string lname;
    Responsible *next;
};
Responsible* Responsiblehead = NULL;
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
void load_students();
void load_foods();
void load_responsibles();

int main()
{
    
    
    
    int choice = -1;
    while (choice != 0)
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
        {
            add_student();
            break;
        }
        case 2:
        {
            enter_student();
            break;
        }
        case 3:
        {
            add_responsible();
            break;
        }
        case 4:
        {
            enter_responsible();
            break;
        }
        case 0:
            exit(0);
            break;
        default:
        {
            cout << "invalid input!" << endl;
            break;
        }
        }
    }
}
void enter_responsible()
{
    Responsible enters;
    ifstream File("respo.txt");
    bool found = false;
    string enterPw, enterName;
    cout << "please enter responsible password: ";
    cin >> enterPw;
    cout << "please enter responsible first name for search: ";
    cin >> enterName;
    while (File >> enters.password >> enters.fname >> enters.lname)
    {
        if (enters.password == enterPw && enters.fname == enterName)
        {
            found = true;
            cout << "password: " << enters.password << endl;
            cout << "first name: " << enters.fname << endl;
            cout << "last name: " << enters.lname << endl;
        }
    }
    File.close();
    if (!found)
    {
        cout << "responsible not found!" << endl;
        return;
    }
    int subb = -1;
    cout << "responsible found!" << endl;
    while (subb != 0)
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
             << "10. exit" << endl;
        cin.ignore();
        cin >> subb;
        switch (subb)
        {
        case 1:
        {
            add_foods();
            break;
        }
        case 2:
        {
            read_food();
            break;
        }
        case 3:
        {
            view_rese();
            break;
        }
        case 4:
        {
            chargestudent();
            break;
        }
        case 5:
        {
            editstudent();
            break;
        }
        case 6:
        {
            view_stu();
            break;
        }
        case 7:
        {
            view_respo();
            break;
        }
        case 8:
        {
            delfood_plan();
            break;
        }
        case 9:
        {
            edit_food();
            break;
        }
        case 10:
        {
            return;
            break;
        }
        default:
        {
            cout << "choose a correct item!" << endl;
            break;
        }
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
        Register* newStudent = new Register;
        cout << "please enter student ID number: ";
        cin >> newStudent->IDnumber;
        cout << "please enter a password: ";
        cin >> newStudent->password;
        cout << "please enter student first name: ";
        cin >> newStudent->fname;
        cout << "please enter student last name: ";
        cin >> newStudent->lname;
        cout << "please enter student phone number: ";
        cin >> newStudent->phonenumber;
        cout << "please enter student money: ";
        cin >> newStudent->money;
        
        
        newStudent->next = Registerhead;
        Registerhead = newStudent;
        
        cout << "Student has been added" << endl;
    }
    
    
    ofstream file("studentt.txt");
    Register* current = Registerhead;
    while (current != nullptr)
    {
        file << current->IDnumber << ' ' << current->password << ' ' << current->fname << ' '
             << current->lname << ' ' << current->phonenumber << ' ' << current->money << endl;
        current = current->next;
    }
    file.close();
}
void add_responsible()
{
    cout << "how many responsible do you want add? ";
    int a;
    cin >> a;
    ofstream file("respo.txt", ios::app);
    for (int i = 0; i < a; i++)
    {

        Responsible enters;
        cout << "please enter password: ";
        cin >> enters.password;
        cout << "please enter first name: ";
        cin >> enters.fname;
        cout << "please enter last name: ";
        cin >> enters.lname;
        file << enters.password << ' ' << enters.fname << ' ' << enters.lname << endl;

        cout << "responsible has been added" << endl;
    }
    file.close();
}
void enter_student()
{
    string enterId, enterPass;
    cout << "please enter student ID number for search: ";
    cin >> enterId;
    cout << "please enter student password for search: ";
    cin >> enterPass;
    
    Register* current = Registerhead;
    bool found = false;
    
    while (current != nullptr)
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
    int sub;
    while (sub != 7)
    {
        cout << "portal:" << endl;
        cout << "choose an item:" << endl
             << "1. view food plan" << endl
             << "2. reserve food" << endl
             << "3. cancel reservation" << endl
             << "4. view reservation" << endl
             << "5. edit student" << endl
             << "6. charge student" << endl
             << "7. exit" << endl;

        cin >> sub;
        switch (sub)
        {
        case 1:
        {
            read_food();
            break;
        }
        case 2:
        {
            reserve_food();
            break;
        }
        case 3:
        {
            cancel();
            break;
        }
        case 4:
        {
            view_rese();
            break;
        }
        case 5:
        {
            editstudent();
            break;
        }
        case 6:
        {
            chargestudent();
            break;
        }
        case 7:
        {
            return;
            break;
        }
        default:
        {
            cout << "choose a correct item!" << endl;
            break;
        }
        }
    }
}

void add_foods()
{
    ofstream File("foods.txt", ios::app);

    int a;
    cout << "how many food do you want add? ";
    cin >> a;
    string foodname, day, dinnerorlunch, date, id;
    int capacity, price;
    for (int i = 0; i < a; i++)
    {
        Food *newFood = new Food;

        cout << "please enter food name:";
        cin >> foodname;
        newFood->foodname = foodname;
        cout << "please enter food price: (rial)";
        cin >> price;
        newFood->price = price;
        cout << "please enter food day: | saterday |sunday| monday| tuesday|wednesday|thursday|friday |";
        cin >> day;
        newFood->day = day;
        cout << "please enter that food is for dinner or lunch:";
        cin >> dinnerorlunch;
        newFood->dinnerorlunch = dinnerorlunch;
        cout << "please enter food date : (ex:1403.10.10)";
        cin >> date;
        newFood->date = date;
        cout << "please enter food capacity:";
        cin >> capacity;
        newFood->capacity = capacity;
        cout << "please enter food ID ";
        cin >> id;
        newFood->id = id;
        newFood->next = nullptr;
        if (Foodhead == nullptr)
        {
            Foodhead = newFood;
        }
        else
        {
            Food *temp = Foodhead;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newFood;
        }
    }
    Food *tt = Foodhead;
    while (tt != nullptr)
    {
        File << tt->foodname << " " << tt->price << " " << tt->day << " " << tt->dinnerorlunch << " " << tt->date << " " << tt->capacity << " " << tt->id << endl;
        tt = tt->next;
    }

    cout << "food has been added" << endl;
    File.close();
    tt = Foodhead;
    while (tt != nullptr)
    {
        Food *temp = tt;
        tt = tt->next;
        delete temp;
    }
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
    string editID;
    string pass;
    cout << "please enter student ID that you want to edit:";
    cin >> editID;
    cout << "enter password: ";
    cin >> pass;
    
    Register* current = Registerhead;
    bool found = false;
    
    while (current != nullptr)
    {
        if (current->IDnumber == editID && current->password == pass)
        {
            found = true;
            cout << "Current first name: " << current->fname << endl;
            cout << "New first name: ";
            cin >> current->fname;
            cout << "Current last name: " << current->lname << endl;
            cout << "New last name: ";
            cin >> current->lname;
            cout << "Current phone number: " << current->phonenumber << endl;
            cout << "New phone number: ";
            cin >> current->phonenumber;
            cout << "Current money: " << current->money << endl;
            cout << "New money: ";
            cin >> current->money;
            break;
        }
        current = current->next;
    }
    
    if (found)
    {
        
        ofstream file("studentt.txt");
        current = Registerhead;
        while (current != nullptr)
        {
            file << current->IDnumber << " " << current->password << " " << current->fname << " "
                 << current->lname << " " << current->phonenumber << " " << current->money << endl;
            current = current->next;
        }
        file.close();
        cout << "Student edited successfully!" << endl;
    }
    else
    {
        cout << "Student not found!" << endl;
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

    if (stu == true)
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
    bool yes = false;
    while (foodplan >> foods.foodname >> foods.price >> foods.day >> foods.dinnerorlunch >> foods.date >> foods.capacity >> foods.id)
    {
        if (foods.foodname == foodname && foods.id == id)
        {
            yes = true;
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
    if (true)
    {
        cout << "deleted!";
    }
}
void edit_food()
{
    fstream file("foods.txt", ios::in | ios::out);
    string editFoodName;
    string editFoodId;
    cout << "Please enter food name that you want to edit: ";
    cin >> editFoodName;
    cout << "Please enter food ID: ";
    cin >> editFoodId;
    
    Food foods;
    ofstream efile("editfood.txt");
    bool found = false;

    while (file >> foods.foodname >> foods.price >> foods.day >> foods.dinnerorlunch >> foods.date >> foods.capacity >> foods.id)
    {
        if (foods.foodname == editFoodName && foods.id == editFoodId)
        {
            found = true;
            cout << "Current price: " << foods.price << endl;
            cout << "New price: ";
            cin >> foods.price;
            cout << "Current day: " << foods.day << endl;
            cout << "New day: ";
            cin >> foods.day;
            cout << "Current meal type (dinner/lunch): " << foods.dinnerorlunch << endl;
            cout << "New meal type: ";
            cin >> foods.dinnerorlunch;
            cout << "Current date: " << foods.date << endl;
            cout << "New date: ";
            cin >> foods.date;
            cout << "Current capacity: " << foods.capacity << endl;
            cout << "New capacity: ";
            cin >> foods.capacity;
        }
        efile << foods.foodname << " " << foods.price << " " << foods.day << " " 
              << foods.dinnerorlunch << " " << foods.date << " " << foods.capacity << " " 
              << foods.id << endl;
    }

    file.close();
    efile.close();
    remove("foods.txt");
    rename("editfood.txt", "foods.txt");

    if (found)
    {
        cout << "Food item updated successfully!" << endl;
    }
    else
    {
        cout << "Food item not found!" << endl;
    }
}
void load_students()
{
    ifstream file("studentt.txt");
    
    
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Register* newStudent = new Register;
        iss >> newStudent->IDnumber >> newStudent->password >> newStudent->fname 
            >> newStudent->lname >> newStudent->phonenumber >> newStudent->money;
        newStudent->next = Registerhead;
        Registerhead = newStudent;
    }
    file.close();
}

void load_foods()
{
    ifstream file("foods.txt");
    
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Food* newFood = new Food;
        iss >> newFood->foodname >> newFood->price >> newFood->day 
            >> newFood->dinnerorlunch >> newFood->date >> newFood->capacity >> newFood->id;
        newFood->next = Foodhead;
        Foodhead = newFood;
    }
    file.close();
}

void load_responsibles()
{
    ifstream file("respo.txt");

    
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Responsible* newResp = new Responsible;
        iss >> newResp->password >> newResp->fname >> newResp->lname;
        newResp->next = Responsiblehead;
        Responsiblehead = newResp;
    }
    file.close();
}
