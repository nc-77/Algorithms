#include<bits/stdc++.h>
#define ll long long
using namespace std;
int vis[25],r[25],flag,cnt,n,num;
int g[25][25];
void dfs(int x,int cnt)
{	if(flag) return;
	if(!flag) r[cnt]=x;
	if(cnt==n)
	{	
			if(g[x][1]==1)
			{
				flag=1;
				return;
			}
		
		
	}
	int f = 1;
    for(int i = 1; i <=n; i ++)
    {
        if(!vis[i] && g[i][1]) f = 0;
    }
    if(f)return;
	//cout<<x<<" "<<cnt<<endl;
	for(int i=1;i<=n;i++)
	{	if(vis[i]||!g[x][i]) continue;
		vis[i]=1;
		dfs(i,cnt+1);
		vis[i]=0;
	}
}
int main()
{	

	cin>>n;
	getchar();
	char ch;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf(" %c",&ch);
			if(ch=='W')
			g[i][j]=1;
			if(ch=='L')
			g[j][i]=1;
		}
	}
		flag=0;
		memset(vis,0,sizeof(vis));
		memset(r,0,sizeof(r));
		vis[1]=1;
		dfs(1,1);
		if(flag) 
		{
			for(int i=1;i<=n;i++)
			{
				if(i!=n)
				cout<<r[i]<<" ";
				else 
				cout<<r[i];
			}
		}
		else puts("No Solution");
}
