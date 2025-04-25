#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream t("test.txt",ios::app);                                //  ofstream t;  t.open("test.txt");
    int b;
    cin >> b;
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "z ";
            t << "z ";
        }
        cout << endl;
        t << endl;
    }
   /* ifstream s("test.txt");
    int a;
    s >> a;
    cout << a << endl;
    while (s >> a) //while(!t.eof()) s>>a; cout<<a<<endl;(baraye char ham mishe estefade kard)
    {

        cout << a << endl;
    }*/
}
