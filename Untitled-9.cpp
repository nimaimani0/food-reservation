#include <iostream>
using namespace std; //nima imani 403103222
int factoriel(int a);
void oddeven(int a);
int fibonachi(int a);
void binary(int a);
int main()
{
    int a, n;
    while (a != -1)
    {
        cout << "please enter a number";
        cin >> a;
        cout << "please choose a function: | factoriel:1 | fibonachi:2 | oddeven :3| binary:4 ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << factoriel(a) << endl;
            break;
        case 2:
            cout << fibonachi(a) << endl;
            break;
        case 3:
            oddeven(a);
            break;
        case 4:
            binary(a);
            break;
        default:
            cout << "you are stupid!";
            break;
        }
    }
}
int factoriel(int a)
{
    if (a <= 1)
        return 1;
    return a * factoriel(a - 1);
}
int fibonachi(int a)
{
    if (a <= 1)
    {
        return a;
    }
    return fibonachi(a - 1) + fibonachi(a - 2);
}
void oddeven(int a)
{
    int Even = 0;
    int Odd = 0;

    while (a > 0)
    {
        int b = a % 10;
        if (b % 2 == 0)
        {
            Even++;
        }
        else
        {
            Odd++;
        }
        a /= 10;
    }

    cout << "the number of even number(s):" << Even << endl
         << "the number of odd number(s):" << Odd << endl;
}

void binary(int a)
{
    int b;
    b = a % 2;
    cout << b;
    if (a > 1)
        binary(a / 2);
    return;
}
