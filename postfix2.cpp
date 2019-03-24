#include<iostream>
using namespace std;

class postfix
{
	public:
	char a[100],oper[20];
	int n,i,top;
	int len(char [] );
	postfix()
	{
		cout<<"Enter the elements\n";
		cin>>a;
		top=-1;
	}
	void arrange()
	{
		n=len(a);
		int j,k;
		for(i=0;i<n;i++)
		{
		 if(a[i]=='(')
			{
				oper[i]=a[i];
				for(j=i;a[i]!=')';i++,j++)
					fix(a[j]);		
			}
			else
				fix(a[i]);
						
		}
		
	}
	
	void fix(char x)
	{
		char b[100];
		int k;
		if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='%')
		{
			while(1)
			{
				if(pre(x)<pre(oper[top]))
					{
						oper[++top]=x;
						break;
					}
				else
					b[i]=oper[top--];
			}
		}
		else
			b[i]=a[i];	
		k=len(b);
		while(top!=-1)
			b[++k]=oper[top--];	
		cout<<b;	
		
	}
	int pre(char x)
	{
		if(x=='*' || x=='/')
			return 1;
		if(x=='+' || x=='-')
			return 2;
		if(x=='%')
			return 3;
	}
	
	
};

int postfix :: len(char ch[])
{
	int n=0;
	for(int i=0;ch[i]!='\0';i++)
		n++;
	return(n);	
}
int main()
{
	postfix p;
	p.arrange();
}
