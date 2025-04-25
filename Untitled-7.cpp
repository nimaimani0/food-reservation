#include<iostream>
using namespace std; //nima imani 403103222
int main()
{
	int n,m,min,max;
	cin>>n;
	cin>>m;
	if(m==0)
	{
		min=0;
		max=0;
	}
	else if(m==1)
	{
		if(n==1)
		{
			max=0;
			min=0;
		}
		else if(n==2)
		{
			min=1;
			max=1;
		}
		else if(n>=3)
		{
			min=1;
			max=2;
		}
	}
	else if(m==2)
	{
		if(n==2)
		{
			min=0;
			max=0;
		}
		else if(n==3)
		{
			min=1;
			max=1;
		}
		else if(n==4)
		{
			min=1;
			max=2;
		}
		else if(n==5)
		{
			min=1;
			max=3;
		}
		else 
		{
			min=1;
			max=4;
		}
	}
	else 
	{
		if(n==m)
		{
			min=0;
			max=0;
		}
		else if(n==1)
		{
			min=0;
			max=0;
		}
		else if(n>=(m*3))
		{
			min=1;
		    max=m*2;
		}
		else 
		{
			min=1;
			max=n-m;
		}
	
	}
	
	cout<<min<<" "<<max;
	
}