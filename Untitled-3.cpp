#include <iostream>
using namespace std; //nima imani 403103222
int factoriel(int n);
int fiboonachi(int n);
int root(int n);
int square(int n);
int main()
{

    int n, x;

    while (x != 0)
    {
        cout <<"\t"<< "please enter a number";
        cin >> x;
        cout << "choose one function: \n | factoriel:1  |  fiboonachi:2  |  root:3 |  square :4 | return:0 ";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << factoriel(x) << "\n";
            break;
        case 2:
            cout << fiboonachi(x) << "\n";
            break;
        case 3:
            cout << root(x) << "\n";
            break;
        case 4:
            cout << square(x) << "\n";
            break;
        case 0:
            cout << "bye" << "\n";
            exit(0);
            break;
        default:
            cout << "please enter one of numbers in list";
            break;
        }
    }
}
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
    do
    {
        i++;
    } while (i * i < n);
    return i ;
}
int square(int n)
{
    if (n <= 1)
        return 0;
    return n * n + square(n - 1);
}
