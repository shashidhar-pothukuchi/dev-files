#include<iostream>
using namespace std;

class matrix
{
	public:
		int map(int,int);//location
		int r,c,i;
		void getmatrix(const matrix &b)
		{
			cout<<"Enter no. of rows\n";
			cin>>r;
			cout<<"Enter no. of coloumns\n";
			cin>>c;
			int *m=new int[r*c];
			cout<<"Enter elements\n";
			for(i=0;i<(r*c);i++)
				cin>>m[i];
			for(i=0;i<(r*c);i++)
				cout<<m[i];	
			
			int i,j,k=0,p;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					k=0;
					for(p=0;p<b.c;p++)
						k +=m[map(i,p)]*b.m[map(p,j)];
						
					cout<<k<<" ";	
				}
				cout<<endl;
			}
		}
		
};

int matrix :: map(int i,int j)
{
	int k;
	k=(i*r)+j;
	return(k);
}

int main()
{
	matrix a,b;
	a.getmatrix(b);
	
}
