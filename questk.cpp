#include<iostream>
#include<stdlib.h>
using namespace std;

class stack
{
	public:
	int stk[20],rear,tos,size;
		
	stack()
	{
			tos=-1;
			rear=-1;
			cout<<"Enter size\n";
			cin>>size;
	}
	
	void enque(int x)
	{
		if(tos==size-1)
		{
			cout<<"Queue overflow\n";
			
		}
		else if(tos==-1)
		{
			stk[++tos]=x;
			cout<<"Inserted "<<x<<endl;
			reverse(stk,tos);
		}
		else if(tos!=-1)
		{
			reverse(stk,tos);
			stk[++tos]=x;
			cout<<"Inserted "<<x<<endl<<tos<<endl;
			rear++;
			reverse(stk,tos);
		}
		
		return;
	}	
		
		void deque()
		{
			if(tos==-1)
				cout<<"Queue empty\n";
			else
			{
				cout<<"Deleted "<<stk[tos--]<<endl;
				
				
				}	
			return;
		}
		
		void display()
		{
		
			cout<<endl;
			if(tos==-1)
				cout<<"Queue empty\n";
			else
			{
				for(int i=tos;i>=0;i--)
					cout<<stk[i]<<" ";
			}	
			return;
		}
		
		void reverse(int stk[],int tos)
		{
			int i,j,k,temp;
			j=tos;
			
			for(i=0;i<((tos+1)/2);i++)
			{
				
				temp=stk[i];
				stk[i]=stk[j];
				stk[j]=temp;
				j--;
			}
			temp=tos;
			tos=rear;
			rear=temp;
			return;
		}
};


int main()
{
	stack s;
	int c;
	while(1)
	{
		cout<<"Enter operation\n";
		cout<<"1.Enqueue 2.Dequeue 3.Display 4.Exit\n";
		cin>>c;
		switch(c)
		{
			case 1:cout<<"enter element\n";
				   cin>>c;
				   s.enque(c);
				   break;
			case 2:s.deque();break;
			case 3:s.display();break;
			default:exit(0);
		 	
		}
	}
}
