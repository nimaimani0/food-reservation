#include <iostream>
using namespace std; // nima imani 403103222 dorbin madar baste
int main() {
    
    int x,y,i,j,m,n,f,g;
    cin >> x >> y;
    cin >> i >> j;
    cin >> m >> n;

    if (x==m) {f=i;}
    else if(x==i) {f=m;}
    else if(m==i) {f=x;}

    if (y==n) {g=j;}
    else if(y==j) {g=n;}
    else if(n==j) {g=y;}

    cout << f << " " << g; 
}