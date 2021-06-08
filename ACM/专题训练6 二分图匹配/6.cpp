#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int maxn=10000+100;
vector<int>d[maxn];
int p[maxn],vis[maxn],match[maxn];
bool dfs(int x)
{
	
	for(int i=0;i<d[x].size();i++)
	{
		int u=d[x][i];
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
	while(cin>>n>>m)
	{	memset(p,0,sizeof(p));
		memset(match,0,sizeof(match));
		for(int i=1;i<=n*m;i++)
		d[i].clear();
		if(n==0&&m==0) break;
		cin>>k;
		for(int i=1;i<=n*m;i++)
		p[i]=1;
		while(k--)
		{	int x,y;
			cin>>x>>y;
			int pos=(x-1)*m+y;
			p[pos]=0;
		}
		for(int i=1;i<=n*m;i++)	
		{	if(!p[i]) continue;
			if(p[i-1]&&i%m!=1) d[i].push_back(i-1);
			 if(p[i+1]&&i%m!=0) d[i].push_back(i+1);
			 if(i+m<=maxn&&p[i+m]) d[i].push_back(i+m);
			 if(i-m>=0&&p[i-m]) d[i].push_back(i-m);
		}
		int res=0;
		for(int i=1;i<=n*m;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) res++;
		}
		cout<<res/2<<endl;
		//cout<<match[16]<<endl;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n*m;i++)
		{	if(vis[i]) continue;
			if(match[i])
			{	int x=match[i];
				if(vis[x]) continue;
				if(i<x)
				printf("(%d,%d)--(%d,%d)\n",i%m?i/m+1:i/m,(i+m-1)%m+1,x%m?x/m+1:x/m,(x+m-1)%m+1);
				else
				printf("(%d,%d)--(%d,%d)\n",x%m?x/m+1:x/m,(x+m-1)%m+1,i%m?i/m+1:i/m,(i+m-1)%m+1);
				
				vis[i]=vis[x]=1;
			}
		}
	}
} 
