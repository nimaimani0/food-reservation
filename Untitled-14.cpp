#include <iostream>
int main()
{

    int ID[3], newID;
    string fName[3], lName[3];
    bool flag = false;

    for (int i = 0; i < 3; i++)
    {
        cout << "please enter your f-name:";
        cin >> fName[i];
        cout << "please enter your l-name:";
        cin >> lName[i];
        cout << "please enter your ID number:";
        cin >> ID[i];
        cout << "______________________________" <<endl;
    }
    cout << "please enter your ID number for search:";
    cin >> newID;
    for (int i = 0; i < 3; i++)
    {
        if (ID[i] == newID)
        {
            cout << "______________________________" << endl;
            cout << "f-Name is : " << fName[i] << endl
                 << "l-Name is : " << lName[i];
            flag = true;
        }
    }
    if (flag == false)
    {
        cout << "not found";
    }
}
