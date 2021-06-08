#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=200;
vector<int>g[maxn];
int vis[maxn],match[maxn];
bool dfs(int x)
{
	for(int i=0;i<g[x].size();i++)
	{
		int u=g[x][i];
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
	int t;
	cin>>t;
	while(t--)
	{	for(int i=0;i<=maxn;i++)
		g[i].clear();
		int n,m;
		cin>>n>>m;
		while(m--)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
		}
		int res=0;
		memset(match,0,sizeof(match));
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) res++;
		}
		cout<<n-res<<endl;
	}
}
