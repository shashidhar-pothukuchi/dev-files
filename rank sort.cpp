#include<iostream>
using namespace std;


class  search
{
	public:
	void rank(int a[],int n, int r[])
	{
		int i,j;
		for(i=0;i<n;i++)
			r[i]=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<i;j++)
			{
				if(a[j]<=a[i])
					r[i]++;
				else
					r[j]++;	
			}
		}
	for(i=0;i<n;i++)
		cout<<r[i];
	return;		
	}
	void rearrange(int a[],int n,int r[])
	{
		int *u=new int[n];int i;
		for(i=0;i<n;i++)
			u[r[i]]=a[i];
		for(i=0;i<n;i++)
			a[i]=u[i];
		delete []u;
		return;	
	}
};

int main()
{
	search s;int i;
	int a[100],n,r[100];
	cout<<"Enter no. of elements\n";
	cin>>n;
	cout<<"enter elements\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	s.rank(a,n,r);
	s.rearrange(a,n,r);
	cout<<"Sorted list\n";
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";	
}
