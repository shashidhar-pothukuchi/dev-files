#include<iostream>
using namespace std;

#define MAX 10
class DFS
{
	private:
		int n,adj[MAX][MAX],visited[MAX];
	public:
		void dfs(int );
		void readmatrix();
};

void DFS :: readmatrix()
{
	int i;
	cout<<"Enter no. of vertices in graph\n";
	cin>>n;
	cout<<"Enter adjacent matrix\n";
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>adj[i][j];
	}
	for(i=1;i<=n;i++)
		visited[i]=0;
}

void DFS :: dfs(int s)
{
	visited[s]=1;
	cout<<s<<" ";
	for(int i=1;i<=n;i++)
	{
		if(adj[s][i] && !visited[i])
			dfs(i);		
	}
}

int main()
{
	int s;
	DFS d;
	d.readmatrix();
	cout<<"Enter source\n";
	cin>>s;
	cout<<"Nodes visited in DFS order :\n";
	d.dfs(s);cout<<endl;
}
