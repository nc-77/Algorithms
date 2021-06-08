#include<bits/stdc++.h>
using namespace std;
int d[150][150],match[150],vis[150];
char a[10][10];
int n;
bool dfs(int x)
{
	for(int i=1;i<=n+n;i++)
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
	while(cin>>n&&n)
	{	memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		memset(match,0,sizeof(match));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				if(a[i][j]=='X') 
				{
					a[i+n][j+n]=a[i+n][j]=a[i][j+n]='X';
				}
			}
		if(n<=2)
		{
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			if(a[i][j]!='X') d[i][j]=1;
			int res=0;
			for(int i=1;i<=n;i++)
			{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) res++;
			}
		cout<<res<<endl;
		continue;
		}	
			
		int f1[10]={0},f2[10]={0};
		for(int i=1;i<=n;i++)
		f1[i]=f2[i]=1;
		for(int i=n+1;i<=n+n;i++)
		{
			if(a[i-n][2]=='X'&&a[i-n][1]!='X'&&a[i-n][3]!='X')
			{
				f1[i]=1;
				
			}
			else if(a[i-n][3]=='X'&&a[i-n][4]!='X'&&a[i-n][2]!='X')
			{
				f1[i]=1;
			
			}
		}
		for(int i=n+1;i<=n+n;i++)
		{
			if(a[2][i-n]=='X'&&a[1][i-n]!='X'&&a[3][i-n]!='X')
			{
				f2[i]=1;
				
				
			}
			else if(a[3][i-n]=='X'&&a[4][i-n]!='X'&&a[2][i-n]!='X')
			{
				f2[i]=1;
				
			}
		}
		
		for(int i=1;i<=n+n;i++)
		{
				if(!f1[i]) continue;
			for(int j=1;j<=n+n;j++)
			{
				if(!f2[j]) continue;
				
				if(a[i][j]!='X')  d[i][j]=1;
			}
		}
			
	
		int res=0;
		for(int i=1;i<=n+n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i)) res++;
		}
		cout<<res<<endl;
	}
}
