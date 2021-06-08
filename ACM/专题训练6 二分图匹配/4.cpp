#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int a[105][105],d[105][105],match[105],vis[105];
vector<PII>g[55];
int n,m,k;
bool dfs(int x)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&d[x][i])
		{
			vis[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=x;
				return true;
			}
		}
	}
	return false;
}
int main()

{
	while(cin>>n>>k)
	{
		if(n==0&&k==0) break;
	
		int v[55];
		memset(v,0,sizeof(v));
		for(int i=1;i<=50;i++)
		g[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				v[a[i][j]]=1;
				g[a[i][j]].push_back({i,j});
			}
		}
		int f=0;
		for(int i=1;i<=50;i++)
		{	if(!v[i]) continue;
			memset(d,0,sizeof(d));
			memset(match,0,sizeof(match));
			for(int j=0;j<g[i].size();j++)
			{
				int x=g[i][j].first;
				int y=g[i][j].second;
				d[x][y]=1;
			}
			int res=0;
			for(int k=1;k<=n;k++)
			{	memset(vis,0,sizeof(vis));
				if(dfs(k)) res++;
			}
			if(res>k) 
			{	
				if(!f)
				{
					f=1;
				cout<<i;
				}
				else 
				cout<<" "<<i; 
			}
			
		}
		if(!f) puts("-1");
		else cout<<"\n";
	}
}
