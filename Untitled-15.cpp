#include <iostream>
using namespace std;
int main()
{
    int a, b = 0;
    cin >> a;
    while (a >= 1)
    {
        b = b + a;
        cin >> a;
    }

    cout << b;
}
