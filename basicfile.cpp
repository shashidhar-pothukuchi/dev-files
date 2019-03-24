#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int data;
	ofstream o;
	o.open("basic.txt",ios::app);
	cout<<"Enter data\n";
	cin>>data;
	o<<data<<" This is a sample";
	o.close();
}
