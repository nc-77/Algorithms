#include<bits/stdc++.h>
using namespace std;
int d[30][30],match[30],vis[30];
int n;
struct node
{
	int  hs;
	int  ds;
}card[30];
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
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			char x,y;
			cin>>x>>y;
			if(x>='2'&&x<='9') card[i].ds=x-'0';
			else if(x=='T')   card[i].ds=10;
			else if(x=='J')   card[i].ds=11;
			else if(x=='Q')   card[i].ds=12;
			else if(x=='K')   card[i].ds=13;
			else if(x=='A')   card[i].ds=14;
			if(y=='H') card[i].hs=4;
			if(y=='S') card[i].hs=3;
			if(y=='D') card[i].hs=2;
			if(y=='C') card[i].hs=1;
		}
		for(int i=1;i<=n;i++)
		{
			char x,y;
			int a,b;
			cin>>x>>y;
			if(x>='2'&&x<='9') a=x-'0';
			else if(x=='T')   a=10;
			else if(x=='J')   a=11;
			else if(x=='Q')   a=12;
			else if(x=='K')   a=13;
			else if(x=='A')   a=14;
			if(y=='H') b=4;
			if(y=='S') b=3;
			if(y=='D') b=2;
			if(y=='C') b=1;
			for(int j=1;j<=n;j++)
			{
				if(a>card[j].ds) d[i][j]=1;
				else if(a==card[j].ds&&b>card[j].hs) d[i][j]=1;
			}
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
