#include<bits/stdc++.h>
using namespace std;
int d[150][150],match[150],vis[150],t[150];
int n,m,k;
bool dfs1(int x)
{
	for(int i=1;i<=m;i++)
	{
		if(!vis[i]&&d[x][i])
		{
			vis[i]=1;
			if(!match[i]||dfs1(match[i]))
			{
				match[i]=x;
				t[i]=x;
				return true;
			}
		}
	}
	return false;
}
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
	int cnt=0;
	while(cin>>n)
	{	cin>>m>>k;

		memset(d,0,sizeof(d));
		while(k--)
		{
			int x,y;
			cin>>x>>y;
			d[x][y]=1;
		}
		memset(match,0,sizeof(match));
		int ans=0;
		for(int i=1;i<=n;i++)
		{	memset(vis,0,sizeof(vis));
			if(dfs1(i)) ans++;
		}
		int im=0;
		
		for(int i=1;i<=m;i++)
		{	int res=0;
		//cout<<t[1]<<" "<<t[2]<<" "<<t[3]<<endl;
			if(t[i]>0) 
			{	memset(match,0,sizeof(match));
				d[t[i]][i]=0;
				//cout<<t[i]<<" "<<i<<endl;
				for(int j=1;j<=n;j++)
				{	memset(vis,0,sizeof(vis));
				if(dfs(j)) res++;
				}
				d[t[i]][i]=1;
				if(res<ans) im++;
			}
			
		}
		printf("Board %d have %d important blanks for %d chessmen.\n",++cnt,im,ans);
	}

 } 
