#include<iostream>
using namespace std;

class A
{
	public:
		void fun();
};

void A::fun()
{
	cout<<"Functon is called!";
}

int main()
{
	A a;
	a.fun();
}
