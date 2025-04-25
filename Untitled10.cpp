#include <iostream>
using namespace std;
int factoriel(int n)
{
    if (n <= 0)
        return 0;
    return n * factoriel(n - 1);
}
int fiboonachi(int n)
{
    if (n <= 1)
        return 0;
    return fiboonachi(n - 1) + fiboonachi(n - 2);
}
int root(int n)
{
    if (n <= 1)
        return 0;
    int i = 1;
    while (i * i <= n)
    {
        i++;
    }
    return i;
}
int square(int n)
{
    if (n <= 1)
        return 0;
    return n * n + square(n - 1);
}
int main()
{
    int a;
    int n;

    while (a != 0)
    {
        cout << "choose one function: \n | factoriel:1  |  fiboonachi:2  |  root:3 |  square :4 |";
        switch (a)
        {
        case 1:
            cout << factoriel(n);
            break;
        case 2:
            cout << fiboonachi(n);
            break;
        case 3:
            cout << root(n);
            break;
        case 4:
            cout << square(n);
            break;
        default:
            cout << "please enter one of numbers in list";
            break;
        }
    }
}
