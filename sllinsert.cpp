#include<iostream>
#include<stdlib.h>
using namespace std;

class node
{
	public:
	class node *next;
	int data;
};

class base:public node
{
	public:
	node *head=NULL;
	void insertf(int x)
	{
		if(head==NULL)
		{
			head=new node;
			head->data=x;
			head->next=NULL;
			cout<<"Inserted\n";
		}
		else
		{
			node *temp;
			temp=new node;
			temp->next=head;
			head=temp;
			temp->data=x;
			cout<<"Inserted\n";
		}
	return;	
	}
	
	void insertl(int x)
	{
		if(head==NULL)
		{
			head=new node;
			head->data=x;
			head->next=NULL;
			cout<<"Inserted\n";
			
		}
		else
		{
			node *temp,*temp1;
			temp=head;
			while(temp->next!=NULL)
				temp=temp->next;
			temp1=new node;
			temp->next=temp1;
			temp1->next=NULL;
			temp1->data=x;
			cout<<"Inserted\n";	
		}
		return;
	}
	
	void insertm(int x)
	{
		int c,f=0;
		cout<<"Enter the element of ref\n";
		cin>>c;
		node *temp,*temp1;
		temp=head;
		while(temp!=NULL)
		{
			if(temp->data==c)
			{
				temp1=new node;
				temp1->next=temp->next;
				temp->next=temp1;
				temp1->data=x;f++;
				cout<<"Inserted\n";
			}
			temp=temp->next;
		}
		if(f==0)
			cout<<"Element not found\n";	
	}
	
	void display()
	{
		node *temp;
		temp=head;
		if(head==NULL)
			cout<<"linked list empty\n";
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
		return;
	}
};

int main()
{
	base k;
	int x;
	while(1)
	{
		cout<<"1.First 2.Middle 3.Last 4.Display 5.Exit \n";
		cin>>x;
	
		switch(x)
		{
			case 1:	cout<<"Enter element\n";
					cin>>x;
					k.insertf(x);
					break;
			case 2: cout<<"Enter element\n";
					cin>>x;
					k.insertm(x);
					break;
			case 3: cout<<"Enter element\n";
					cin>>x;
					k.insertl(x);
					break;
			case 4: k.display();
					break;
			default:exit(0);
		}
	}
}
