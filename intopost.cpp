#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
template<class T>
class strAr
{
	public:
		T *ar;
		int top,max;
		strAr(int n)
		{
			max=n;
			ar=new T[n];
			top=-1;
		}
		bool isempty()
		{
			if(top==-1)
				return true;
			else
				return false;	
		}
		bool isfull()
		{
			if(top==max)
				return true;
			else
				return false;
		}
		T gettop()
		{
			if(top==-1)
				return NULL;
			else
				return ar[top];
		}
		T push(T x)
		{
			if(isfull())
				return NULL;
			else
				ar[++top]=x;
			
		}
		T pop()
		{
			if(isempty())
				return NULL;
			else
			{
				T y=ar[top--];
				return y;
			}
		}
};
		int prec(char x)
		{
			switch(x)
			{
				case '+' :
				case '-' : return 1;break;
				case '*' :
				case '/' : return 2;break;	
			}
		}
		void intopos(char *x,char *y)
		{
			strAr<char> p (20);
			int pos1=0,pos2=0,len;
			char c,ch;
			p.push('(');
			len=strlen(x);
			x[len]=')';
			x[len++]='\0';
			while(!p.isempty())
			{
				c=x[pos1++];
				if(isalpha(c) || isdigit(c))
					y[pos2++]=c;
				else if(c=='(')
					p.push(c);	
				else if(c==')')
				{
					while((ch=p.pop())!='(')
						y[pos2++]=ch;
				}
				else if(c=='+' || c=='-' || c=='*' || c=='/')
				{
					while(p.gettop()!='(' && prec(p.gettop())>=prec(c))
					{
						ch=p.pop();
						y[pos2++]=ch;
					}
					p.push(c);	
				}
			}	
			y[pos2]='\0';
		}

int main()
{
	char str1[30],str2[30];
	cout<<"Enter infix expression\n";
	cin>>str1;
	intopos(str1,str2);
	cout<<"Postfix expression:\n";
	cout<<str2;
}
