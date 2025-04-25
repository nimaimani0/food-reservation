#include <iostream>
using namespace std; //nima imani  403103222
int main()
{
    int a[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "pleaseb enter numbers";
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum += a[i][j];
        }
    }
    float average = sum / 9;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] > average)
            {
                cout << "number(s)that is/are more than average:" << a[i][j] << endl;
            }
        }
    }
}