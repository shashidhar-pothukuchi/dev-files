#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		friend class matrix;//instead of inheritance
};

class matrix
{
	public:
		node *head;
		int map(int,int);
		int r,c,n,i,j,x;
	matrix()
	{
		cout<<"Enter no. of rows\n";
		cin>>r;
		cout<<"Enter no. of coloumns\n";
		cin>>c;
		n=r*c;
	}
	void getmatrix()
	{
		node *temp ,*temp1;
		cout<<"Enter elements\n";
		head=new node;
		cin>>x;
		head->next=NULL;
		head->data=x;
		for(i=1;i<n;i++)
		{
			cin>>x;
			temp=new node;
			temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp1=new node;
			temp->next=temp1;
			temp1->next=NULL;
			temp1->data=x;	
		}
		return;
	}
	void mul(const matrix & b)
	{
		int k,p,t;
		node *a=head, *q=b.head;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				k=0;
				for(p=0;p<b.c;p++)
				{
					for(t=0;t<map(i,p);t++)
						a=a->next;
					for(t=0;t<map(p,j);t++)
						q=q->next;	
					k += (a->data*q->data);
					
				}
				cout<<k<<" ";
			}
		cout<<endl;
		}
	}
		
};

int matrix::map(int i,int j)
{
	return((i*c)+j);
}


int main()
{
	matrix a,b;
	a.getmatrix();
	b.getmatrix();
	a.mul(b);
}
