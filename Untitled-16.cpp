#include <iostream>
#include <conio.h>
#include <string>

using namespace std;
class tst
{
public :
    void f()
    {
        cout << "hello";
    }

private :
    int a, b;
};
int main()
{
    tst t;
    cout<<t.f;
    /* int b;
     cin>>b;
     for (int i =1; i <= b; i++)
     {
         for (int j = 1; j<= i; j++)
         {
             cout << "z ";
         }
         cout << endl;
     }*/
}