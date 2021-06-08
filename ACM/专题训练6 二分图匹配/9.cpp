#include<bits/stdc++.h>
using namespace std;
const int maxn=500;
int d[maxn][maxn],match[maxn],vis[maxn];
int p,n;
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
	int t;
	cin>>t;
	while(t--)
	{	memset(d,0,sizeof(d));
		cin>>p>>n;
		for(int i=1;i<=p;i++)
		{
			int k;
			cin>>k;
			while(k--)
			{
				int x;
				cin>>x;
				d[i][x]=1;
			}
		}
		memset(match,0,sizeof(match));
		int res=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) res++;
		}
		if(res==p) puts("YES");
		else puts("NO");
	} 
}
