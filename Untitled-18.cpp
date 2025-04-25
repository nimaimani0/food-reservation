#include <iostream>
#include <fstream>
using namespace std;
int main()
{
fstream t("test.txt",ios::in | ios::out | ios::app |ios::binary);
int a ;
t>>a;
cout<<a;







}