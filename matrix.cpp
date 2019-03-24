#include<iostream>
using namespace std;

class matrix
{
	public:
	int r,c,i,j,a[10][10];
	
	matrix()
	{
		cout<<"Enter size\n";
		cout<<"No. of rows\n";
		cin>>r;
		cout<<"No. of coloumns\n";
		cin>>c;
		cout<<"Enter elements\n";
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				cin>>a[i][j];
		}
		
	}
	
	matrix addsub(const matrix &k)
	{
		cout<<"Their addition is\n";
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				cout<<a[i][j]+k.a[i][j]<<" ";
			cout<<endl;	
		}
		cout<<"Their subtraction is\n";
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
				cout<<a[i][j]+k.a[i][j]<<" ";
			cout<<endl;
		}
	}
	
	matrix mul(const matrix &q)
	{
		int b[10][10],k;
		cout<<"Their multiplication is\n";
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				b[i][j]=0;
				for(k=0;k<q.c;k++)
					b[i][j]=b[i][j]+(a[i][k]*q.a[k][j]);
				cout<<b[i][j]<<" ";	
			}
			cout<<endl;
		}
	}
};

int main()
{
	matrix a,b;
	int x;
	cout<<"Enter choice\n1.Addition and subtraction  2.Multiplication\n";
	cin>>x;
	switch(x)
	{
		case 1:if(a.r==b.r && a.c==b.c)
				a.addsub(b);
				else
					cout<<"Addition and subtraction not possible\n";
				break;
		
		case 2:if(a.c==b.r)
				a.mul(b);
				else
					cout<<"Multiplication not possible\n";
				break;				
	}
}
