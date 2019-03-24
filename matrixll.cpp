#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	class node *next;
};

class matrix:public node
{
	public:
	node *head;
	node *temp;
	int n,x,r,c,i;
	matrix()
	{
		cout<<"Enter no. of rows:\n";
		cin>>r;
		cout<<"Enter no. of coloumns\n";
		cin>>c;
		n=r*c;
	}
	void getmatrix()
	{
		node *temp1;
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
	void display()
	{
		cout<<endl;
		node *temp=new node;
		temp=head;
		for(i=0;i<r;i++)
		{
			for(int j=0;j<c;j++)
				{
					cout<<temp->data<<" ";
					temp=temp->next;	
				}
			cout<<endl;	
		}
	return;	
	}
	void add(const matrix &q)
	{
		int z,j;
		node *a=new node,*b=new node;
		a=head;b=q.head;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				z=a->data+b->data;
				cout<<z<<" ";
				a=a->next;b=b->next;
			}
		cout<<endl;		 
		}
	return;	
	}
	
	void sub(const matrix &q)
	{
		int j,z;
		node *a=new node,*b=new node;
		a=head;b=q.head;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				z=a->data-b->data;
				cout<<z<<" ";
				a=a->next;b=b->next;
			}
		cout<<endl;		 
		}
	return;
	}
	
	void mul(const matrix &q)
	{
		int j,t,k,p;
		node *a=new node,*b=new node;
		temp=head;
		node *temp1=q.head;
		node *temp2;
		for(i=0;i<r;i++)
		{
			a=temp;temp2=temp;
			for(t=0;t<r;t++)
			{
				k=0;b=temp1;
				for(j=0;j<c;j++)
				{
					k=k+(a->data*b->data);
					a=a->next;
					for(p=0;p<q.c;p++)
						if(b!=NULL)
							b=b->next;
				}
				cout<<k<<" ";
			if(temp!=NULL)	
				temp=temp->next;
			a=temp2;
			if(temp1!=NULL)
				temp1=temp1->next;
			}
		cout<<endl;	
		}
	}
};

int main()
{
	matrix m1,m2;
	m1.getmatrix();
	m2.getmatrix();
	m1.add(m2);
	m1.display();
	m2.display();
	m1.mul(m2);
}
