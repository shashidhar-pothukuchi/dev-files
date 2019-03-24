#include<iostream>
using namespace std;
template<class T>

T min(int a,int b)
{
	return(a<b?a:b);
	
}

int main()
{
	int a=5,b=10,c;
	c=min(a,b);
	cout<<c;
}
