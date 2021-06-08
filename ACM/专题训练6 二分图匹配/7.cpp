#include<bits/stdc++.h>
using namespace std;
const int maxn=500;
int d[maxn][maxn],match[maxn],vis[maxn];
int n;
bool dfs(int x)
{
	for(int i=0;i<n;i++)
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
	
	while(cin>>n)
	{	getchar();
		memset(d,0,sizeof(d));
		for(int i=0;i<n;i++)
		{	int id,k;
			scanf("%d: (%d)",&id,&k);
			//cout<<id<<k<<endl;
			while(k--)
			{
				int x;
				cin>>x;
				//cout<<x<<endl;
				d[i][x]=1;
			}
		}
		memset(match,0,sizeof(match));
		int res=0;
		for(int i=0;i<n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) res++;
		}  
		//cout<<res<<endl;
		cout<<n-res/2<<endl;
	} 
}
