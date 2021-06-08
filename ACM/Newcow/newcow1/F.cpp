#include<bits/stdc++.h>
using namespace std;
#define MAX_N 111111
#define ll long long
vector<int>g[MAX_N];
int par[MAX_N];
char color[MAX_N];
ll high[MAX_N];
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		high[i]=1;
	}
} 
int find(int x)
{
	if(par[x]==x)
	return x;
	else
	return find(par[x]);
}
void unite(int x,int y)
{	//int m=x,n=y;
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(high[x]<high[y])
	{
		par[x]=y;
		high[y]+=high[x];
		//high[y]++;
		//high[n]=high[m]=high[y];
	}
	else 
	{
		par[y]=x;
		high[x]+=high[y];
		//high[x]++;
		//high[n]=high[n]=high[x];
		
	}
}
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	init(n);
	getchar();
	for(int i=1;i<=n;i++)
	color[i]=getchar();
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x); 
		if(color[x]=='W'&&color[y]=='W')
		unite(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		if(color[i]=='W')
		high[i]=high[find(i)];
	}
//	cout<<high[1]<<" "<<high[5]<<" "<<high[2]<<" "<<high[6]<<endl;
	for(int i=1;i<=n;i++)
	{
		if(color[i]=='B')
		{	ll sum=0;
			for(int j=0;j<g[i].size();j++)
			{
				if(color[g[i][j]]=='W')
				{	//cout<<g[i][j]<<endl;
					ans+=sum*high[g[i][j]]+high[g[i][j]];
					sum+=high[g[i][j]];
					//cout<<ans<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
		
	
	
}
