#include <iostream>
using namespace std;      //nima imani linked list
struct Node
{
    string fname;
    string lname;
    string id;

    Node *Link;
};
void info(Node *&head);
void search_info(Node *&head);
void delete_info(Node *&head);
void show_student(Node *&head);

int main()
{
    Node *head = NULL;
    int choose;
    do
    {

        cout << "please choose an item :" << endl
             << "1-add student | 2-search student | 3-delete student |4-show student |0-exit" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            info(head);
            break;
        case 2:
            search_info(head);
            break;
        case 3:
            delete_info(head);
            break;
        case 4:
            show_student(head);
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "invalid input!" << endl

                 << "please enter correct input ." << endl;
            break;
        }
    } while (choose);
}

void info(Node *&head)
{
    int x = 0;
    cout << "please enter how many students do you want add?" << endl;
    cin >> x;
    for (int i = 0; i < x; i++)
    {
        string firstname, lastname, idn;

        cout << "please enter student first name :" << endl;
        cin >> firstname;

        cout << "please enter student last name:" << endl;
        cin >> lastname;

        bool again;
        do
        {
            again = false;
            cout << "please enter student id number :" << endl;
            cin >> idn;
            Node *t = head;
            while (t != NULL)
            {
                if (t->id == idn)
                {
                    cout << "this id used before" << endl;
                    again = true;
                    break;
                }

                t = t->Link;
            }
        } while (again);
        Node *info = new Node;
        info->fname = firstname;
        info->lname = lastname;
        info->id = idn;
        info->Link = NULL;
        if (head == NULL)
        {
            head = info;
        }
        else
        {
            Node *temp = head;
            while (temp->Link != NULL)
            {
                temp = temp->Link;
            }
            temp->Link = info;
        }
        cout
            << "student information  successfully added!" << endl;
    }
}
void search_info(Node *&head)
{
    string idn;
    bool xi = false;
    Node *temp = head;
    cout << "please enter student id number for searching :" << endl;
    cin >> idn;
    while (temp != NULL)
    {
        if (temp->id == idn)
        {
            cout << "student found!" << endl;
            cout << "first name:" << temp->fname << endl;
            cout << "last name:" << temp->lname << endl;
            cout << "id number :" << temp->id << endl;
            xi = true;
            break;
        }
        temp = temp->Link;
    }
    if (xi == false)
    {
        cout << "student not found!" << endl;
    }
}
void delete_info(Node *&head)
{
    string idn;
    cout << "please enter student number for deleting:" << endl;
    cin >> idn;
    if (head->id == idn)
    {
        Node *temp = head;
        head = head->Link;
        delete temp;
        cout << "student successfully deleted!" << endl;
        return;
    }
    Node *temmp = head;
    while (temmp->Link != NULL)
    {
        if (temmp->Link->id == idn && temmp->Link->Link != NULL)
        {
            Node *temp = temmp->Link;
            temmp->Link = temmp->Link->Link;
            delete temp;
            return;
        }
        if (temmp->Link->id == idn && temmp->Link->Link == NULL)
        {
            Node *temp = temmp->Link;
            ;
            temmp->Link = NULL;
            delete temp;
            cout << "student deleted successfully" << endl;
            return;
        }
        temmp = temmp->Link;
    }

    cout << "student not found" << endl;
}
void show_student(Node *&head)
{
    cout << "student list :" << endl;
    Node *temp = head;
    int num = 1;
    while (temp != NULL)
    {
        cout << "student: " << num << endl;
        cout << "first name: " << temp->fname << endl;
        cout << "last name: " << temp->lname << endl;
        cout << "id number: " << temp->id << endl;
        cout << "***********************************" << endl;
        temp = temp->Link;
        num++;
    }
}