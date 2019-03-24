#include<iostream>
#include<windows.h>
using namespace std;
struct winm//winvalue array
{
	int a,b,c;
};
struct aimove
{
		int x;
	int score;
	aimove(){}
	aimove(int s)
	{
		score=s;
		x=0;
	}
};
	
class engine 
{
	public:
	bool gameover,check,multi;
	int k,humval,comp,rv;
	struct winm w[8];
	int state[9],mat[5][5];

	void setup()
	{//writing wincheck values
	char mul;
		w[1]={0,3,6};
		w[2]={1,4,7};
		w[3]={2,5,8};
		w[4]={0,4,8};
		w[5]={2,4,6};
		w[6]={0,1,2};
		w[7]={3,4,5};
		w[0]={6,7,8};
		for(int i=0;i<9;i++)
		{
			state[i]=0;
			//cout<<state[i];
		}
		cout<<"Multiplayer ? y or n \n ";
		cin>>mul;
		mul=='y' ? multi=true : multi=false; 
		cout<<endl;
		//cout<<multi;Sleep(1000);
	 	gameover = false;
	}	
	void draw()
	{
		int j;
		system("cls");
		//draw engine
		for(int i=1,k=0;i<=5;i++)
		{
			for(j=1;j<=5;j++)
			{	
				if(i%2==0)
				{
					cout<<"_";//drawing horizontal lines
				}
				else if(j%2==0 && j!=1)
					cout<<"|";//drawing vertical lines
				else//X O and spaces
				{
					mat[i-1][j-1]=state[(3*k)+(j/2)];
					if(mat[i-1][j-1]==1)
						cout<<"X";
					else if(mat[i-1][j-1]==-1)
						cout<<"O";
					else 
						cout<<" ";
				}	
			}
			if(i%2==0)
				k++;
			cout<<endl;
			
		}
		for(int k=0;k<9;k++)
		cout<<state[k]<<" ";
		cout<<endl;
	}
	int checkwin()
	{check=false;
		for(int i=0;i<9;i++)
		{
			if(state[w[i].a]==1 && state[w[i].b]==1 && state[w[i].c]==1){
				return 1;check=true;}
			else if(state[w[i].a]==-1 && state[w[i].b]==-1 && state[w[i].c]==-1){
				return -1;check=true;}
		}bool tie=true;		
		for(int k=0;k<9;k++)
		{
			if(state[k]==0)
				tie=false;
			
		}
		if(tie==true)
			return 2;
		if(check==false)
			return 0;
	}
	aimove callai(int state[],int player)
	{//base case check
		aimove aik;int t=0;
		 aimove moves[20];
		rv=checkwin();
		if(rv==1)
			return aimove(10);	 
		else if(rv==-1)
			return aimove(-10);
		else if(rv==0)
			return aimove(0);
		//recrsive part
		for(int i=0;i<9;i++)
		{
			if(state[i]==0)
			{
			 	aimove move;
				move.x=i;
				state[move.x]=player;
				if(player==-1){
					aik=callai(state,1);
					move.score=aik.score;}
				else if(player==1){
					aik=callai(state,-1);
					move.score=aik.score;}
				moves[t++]=move;	
				state[i]=0;
			}		
			
		}
		//picking the best move
		int bestmove,bestscore;
		
		if(player==-1)
		{
			bestscore=-100;
			for(int k=0;k<9;k++)
			{
				if(moves[k].score >= bestscore)
				{
					bestmove=k;
					bestscore=moves[k].score;
				}
			}	
		}
		if(player==1)
		{
			bestscore=100;
			for(int k=0;k<9;k++)
			{
				if(moves[k].score <= bestscore)
				{
					bestmove=k;
					bestscore=moves[k].score;
				}
			}	
		} 
		return moves[bestmove];
	}
	void logic()
	{
		if(checkwin()==1)
		{draw();
			if(multi==false)
				cout<<"You Won!!\n";
			else
				cout<<"Player 1 Won!!\n";
		gameover=true;
		}
		else if(checkwin()==-1)
		{draw();
		if(multi==false)
			cout<<"Computer Won!!\n";
		else
			cout<<"Player 2 Won!!\n";	
		gameover=true;}
		else if(checkwin()==2){draw();
			cout<<"Its a Draw!!\n";gameover=true;}
		
	}
	void input()
	{//Input values
		if(multi==false){
			aimove ai;
			cout<<"Enter position\n";
			cin>>humval;
			if(state[humval-1]==0)
				state[humval-1]=1;
			else{
				cout<<"Select another value\n";Sleep(1000);}
			//calling AI
			ai=callai(state,-1);
			comp=ai.x;
			state[comp]=-1;
		}
		else 
		{
			int p1,p2;
			cout<<"Enter player 1 : ";
			cin>>p1;
			if(state[p1-1]==0)
				state[p1-1]=1;
			else{
				cout<<"Select another value\n";Sleep(1000);}
			if(checkwin()!=0)
				return;	
			draw();	
			cout<<"Enter player 2 : ";	
			cin>>p2;
			if(state[p2-1]==0)
				state[p2-1]=-1;
			else{
				cout<<"Select another value\n";Sleep(1000);}
			if(checkwin()!=0)
				return;	
			draw();			
		}
	}
	
};

int main()
{
	engine e;
	e.setup();
	//recursive function till gameover
	while(!e.gameover)
	{
		e.draw();
		e.input();
		e.logic();
	}
}
