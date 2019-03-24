#include<conio.h>
#include<iostream>

#include<windows.h>
using namespace std;



class game 
{
	public:
		bool go,flag,akash;
		enum edir {stop=0,l,r};
		edir dir;
		int width,height,posb;
		int x,y,posx[100],posy[100];
		int score,life,time;
		int t,k;
	void setup()
	{
		width=height=30;
		score=0;
		go=flag=false;
		time=rand() % 100 + 10;
		x=height-1;
		life=3;
		y=width/2;
		posy[0]=rand() % width;
		posx[0]=1;
		life=3;k=t=0;
		cout<<"\t\t\t\t EGG BASKET \n";
		cout<<endl<<endl<<"\t\t\t ";
	}
	int printbas(int j)
	{
		if(j<1)
			y=width-5;
		else if(j>=width-4)
			y=1;
		return y;
			
	}
	void draw()
	{
		int i;
		system("cls");
		for(i=0;i<width+1;i++)
			cout<<"#";
		cout<<endl;	
		for(i=0;i<height;i++)
		{
			for(int j=0;j<width;j++)
			{
				posb=printbas(y);
				if(j==0 )
					cout<<"#";		
				else if(i==x && j==posb)
				{	
					cout<<"|__|";
					j+=3;
				}	
				else
				{
					akash=false;
					for(int p=0;p<=k;p++)
					{
						if(i==posx[p] && j==posy[p])
						{
							cout<<"0";
							akash=true;
						}
					}
					if(akash==false)
						cout<<" ";
				}
				if(j==width-1)
					cout<<"#";
			}
			cout<<endl;
		}
		for(i=0;i<width+1;i++)
			cout<<"#";
		
		cout<<endl;
	cout<<"score:"<<score<<"\t\t"<<"Life:"<<life;
	
}
	void input()
	{
		if(_kbhit())
		{
			switch(_getch())
			{
				case 'a' : dir=l;
							break;
				case 'd' : dir=r;
							break;
				case 'x' : go=true;
							break;
									
			}
		}
	}	
	
	void multi()
	{
		if(t!=time)
		{
			t++;
		}
		else if(t==time)
		{
			k++;
			if(k==100)
				k=0;
			posx[k]=1;posy[k]=rand() % width + 2;
			time= rand() % 20 + 10;flag=false;
			t=0;
		}
	}
	void logic()
	{
		int p;
		switch(dir)
		{
			case l : y--;
					 break;
			case r: y++;
					break;
		}
		dir=stop;
		for(p=0;p<=k;p++)
		{
			if(posx[p]==x)
			{
				if(posy[p]==(posb+1) || posy[p]==(posb+2))
				{
					score+=10;
					flag=true;
				}
				else if(flag==false)
					life -=1;
			}	
		}
		multi();		
		for(p=0;p<=k;p++)
		posx[p]++;
		if(life==0)
			go=true;
	}
			
		
};


int main()
{
	game g;
	g.setup();
	
	while(!g.go)
	{
		g.draw();
		g.input();
		g.logic();
		Sleep(200);
	}
	system("cls");
	cout<<"\n\n\n\n\n\n\t\tGAMEOVER\n";
	cout<<"Score = "<<g.score;
	Sleep(100);
}

