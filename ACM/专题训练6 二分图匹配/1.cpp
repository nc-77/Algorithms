#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=105;
vector<int>g[maxn];
int vis[maxn],match[maxn];
bool dfs(int x)
{
	
	for(int i=0;i<g[x].size();i++)
	{
		int u=g[x][i];
		//cout<<x<<" "<<u<<endl;
		if(!vis[u])
		{
			vis[u]=1;
			if(!match[u]||dfs(match[u]))
			{
				match[u]=x;
				
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int n,m,k;
	while(cin>>n&&n)
	{	for(int i=0;i<maxn;i++)
		g[i].clear();
		memset(match,0,sizeof(match));
		cin>>m>>k;
		for(int i=0;i<k;i++)
		{
			int id,x,y;
			cin>>id>>x>>y;
			if(x==0||y==0) continue;
			g[x].push_back(y);
			//g[y].push_back(x);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{	memset(vis,0,sizeof(vis));
			if(dfs(i)) 
			{
				ans++;
			//cout<<i<<endl;
			}
			//cout<<"h"<<endl;
			//for(int j=1;j<=4;j++)
			//cout<<match[i]<<endl;
	 	}
	 	cout<<ans<<endl;
	}
}
