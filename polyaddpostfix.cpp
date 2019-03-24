#include <iostream>
using namespace std;

class node
{
public:
	node * next;
	int coeff, exp;
};
class addpoly
{
node * head;
node * temp;
node* temp2;

public:
int count;
	addpoly(){
		count=0;
		head=NULL;
	}
	void insert(int c, int e){
		if (head==NULL){
			head=new node;
			head->next=NULL;
			head->coeff=c;
			head->exp=e;
			cout<<"inserted "<<head->coeff<<"and "<<head->exp<<" ";
			count++;
		}
		else {
			temp=new node;
			temp->next=head;
			temp->exp=e;
			temp->coeff=c;
			cout<<"inserted st "<<temp->coeff<<" "<<"and "<<temp->exp<<" ";
			count++;
			head=temp; 
		}
	}
	void add(addpoly& p){
		temp=head; 		p.temp=p.head;
		for (int i = 0; i < count-1; i++)
		{
			for (int j = 0; j < count-1; j++)
			{
				if (p.temp->exp==temp->exp)
				{
					temp->coeff+=p.temp->coeff;
					p.temp->coeff=0;
					//p.temp2=p.temp; // check this
					//delete p.temp2;
					p.temp=p.temp->next;
				}
			}
			temp=temp->next;
		}
		p.temp=p.head;
		while(p.temp){
			if(p.temp->coeff!=0)
				insert(p.temp->coeff, p.temp->exp);
			p.temp=p.temp->next;
		}

	}
	void display(){
		temp=head;
		while(temp->next){
			cout<<temp->coeff<<"x^"<<temp->exp<<" + ";
			temp=temp->next;
		} cout<<temp->coeff<<"x^"<<temp->exp<<endl;
	}
	
};

int main(){
	int c,e;
	addpoly p, q;
	cout<<"0 to exit\n c&e of 1st: ";
	while(1){
		cin>>c>>e;
		if (c==0) break;
		p.insert(c,e);
	}
	cout<<"0 to exit\n c&e of 2nd: ";
	while(1){
		cin>>c>>e;
		if (c==0) break;
		q.insert(c,e);
	}
	p.add(q);
	p.display();	
}
