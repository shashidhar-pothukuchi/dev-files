#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

class node
{
	public:
	class node *next;
	int data;
};

class stack:public node
{
	public:
	node *head=NULL,*temp;
	int i,x;
		void push(int x)
		{
			if(head==NULL)
			{
				head=new node;
				head->next=NULL;
				head->data=x;
				cout<<"Inserted "<<x<<endl;
			}
			else
			{
				temp=new node;
				temp->next=head;
				temp->data=x;
				head=temp; 
				cout<<"Inserted "<<x<<endl;
			}
			ofstream of;
			of.open("stack.txt",ios::app);
			of<<"Inserted "<<x<<endl;
			temp=head;
			of<<"\t"<<head->data<<"->Top\n";
			temp=temp->next;
			while(temp!=NULL)
			{
				of<<"\t"<<temp->data<<endl;
				temp=temp->next;
			}
			of.close();
			return;
		}
		
		void pop()
		{
			if(head==NULL)
			{
					cout<<"Stack empty\n";
					return;
			}
			else
			{
				
				cout<<"Deleted "<<head->data<<endl;
				x=head->data;
				head=head->next;
				ofstream of;
				of.open("stack.txt",ios::app);
				of<<"Deleted "<<x<<endl;
				temp=head;
				while(temp!=NULL)
				{
					if(temp==head)
						of<<"\t"<<head->data<<" ->Top \n";
					of<<"\t"<<temp->data<<endl;
					temp=temp->next;
				}
				of.close();	
			}
			return;			
		}
		
		void display()
		{
			if(head==NULL)
			{
				cout<<"Stack empty\n";
				return;
			}
			else
			{
				
				temp=head;
				cout<<endl;
				cout<<temp->data<<" ->Top\n";
				temp=temp->next;
				while(temp!=NULL)
				{
					cout<<temp->data<<endl;
					temp=temp->next;
				}
				cout<<endl;
				ofstream of;
				of.open("stack.txt",ios::app);
				of<<"Display\n"<<endl;
				temp=head;
				of<<"\t"<<head->data<<"->Top\n";
				temp=temp->next;
				while(temp!=NULL)
				{
					of<<"\t"<<temp->data<<endl;
					temp=temp->next;
				}
				of.close();
			}	
			return;
		}
		
		void search(int x)
		{
			temp=head;
			bool tr=true;
			if(head==NULL)
			{
				cout<<"Stack empty\n";
				return;
			}
			while(temp!=NULL)
			{
				if(x==temp->data)
				{
					cout<<"Element found!\n";
					tr=false;
				}
			temp=temp->next;	
			}
			if(tr==true)
				cout<<"Element not found\n";
			ofstream of;
			of.open("stack.txt",ios::app);	
			of<<"searched "<<x<<endl;
			temp=head;
			of<<"\t"<<head->data<<"->Top\n";
			temp=temp->next;
			while(temp!=NULL)
			{
				of<<"\t"<<temp->data<<endl;
				temp=temp->next;
			}
			of.close();
			return;	
		}
		
};


int main()
{
	stack s;
	int c,n=0;
	while(1)
	{
		cout<<"1.Push  2.Pop  3.Display  4.Search  5.Count \n\t Any key to Exit\n";
		cout<<"Enter choice\n";
		cin>>c;
		switch(c)
		{
			case 1: cout<<"Enter element\n";
					cin>>c;
					s.push(c);
					n++;
					break;
			case 2: if(n!=0)
						n--;
					s.pop();
					break;
			case 3: s.display();
					break;
			case 4:	cout<<"Enter element to be found \n";
					cin>>c;			
					s.search(c);
					break;
			case 5: cout<<"Count = "<<n<<endl;break;		
			default:exit(0);		
		}
	}
}
