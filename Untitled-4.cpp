#include <iostream>
using namespace std; //nima imani 403103222 
int main()
{
    int n, m, i = 0;
    cin >> n >> m;
    
    if ((n>=m) && ((n-m) %2 ==0)) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}