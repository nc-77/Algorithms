#include<bits/stdc++.h>
using namespace std;
int d[1500][1500],match[1500],vis[1500];
int n,m,k;
bool dfs(int x)
{
	for(int i=1;i<=m;i++)
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
	while(cin>>k&&k)
	{	memset(d,0,sizeof(d));
		cin>>n>>m;
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			d[x][y]=1;
		}
		memset(match,0,sizeof(match));
		int res=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) res++;
		}
		cout<<res<<endl;
	}
	
}
