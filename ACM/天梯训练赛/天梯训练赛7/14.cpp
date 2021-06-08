#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>g[100000+10];
int vis[100000+10];
int dis[10000+10];
void bfs(int x)
{	int d=-1,pos;
	queue<int>que;
	que.push(x);
	dis[x]=0;
	while(!que.empty())
	{	x=que.front();
		que.pop();
		if(dis[x]>d)
		{
			d=dis[x];
			pos=x;
		}
		else if(dis[x]==d&&x<pos)
		pos=x;
		for(int i=0;i<g[x].size();i++)
		{
			if(vis[g[x][i]])  continue;
			que.push(g[x][i]);
			dis[g[x][i]]=dis[x]+1;
			vis[g[x][i]]=1;
			
		}
	}
	cout<<pos<<endl;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	while(k--)
	{	memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		int x;
		cin>>x;
		vis[x]=1;
		if(g[x].empty())
		{
			puts("0");
			continue;
		}
		bfs(x);
	}
}
