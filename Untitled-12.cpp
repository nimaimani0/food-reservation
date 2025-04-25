#include <iostream>
using namespace std; //nima imani 403103222
int root(int n);
int main()
{
    int l;
    cout<<"please enter array size:";
    cin >> l;
    int a[l];
    int i = 0;
    while (i < l)
    {
        cout<<"please enter numbers:"<<endl;
        cin >> a[i];
        cout <<endl<< root(a[i]) << endl;

        i++;
    }
}
int root(int n)
{
    if (n <= 1)
        return 0;
    int i = 0;
    while (i * i < n)
    {
        i++;
    }
    return (i - 1);
}