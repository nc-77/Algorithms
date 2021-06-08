#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int par[maxn],vis[maxn],d[maxn][maxn];
void init(int n)
{
	for(int i=0;i<n;i++)
	par[i]=i;
}
int find(int x)
{
	if(par[x]==x) return x;
	else
	return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	else par[x]=y;
}
int main()
{
	int n,m,sum=0;
	cin>>n>>m;
	init(n);
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		d[x][y]=1;
		unite(x,y);
	}
	for(int i=0;i<n;i++)
	{
		if(par[i]==i) sum++;
	 } 
	 //cout<<sum<<endl;
	int q,ssum=0,tot=0;
	cin>>q;
	while(q--)
	{	ssum=0;
		tot++;
		int lose;
		cin>>lose;
		init(n);
		for(int i=0;i<n;i++)
		vis[lose]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][j]&&!vis[i]&&!vis[j])
					unite(i,j);
		for(int i=0;i<n;i++)
		{
			if(par[i]==i&&!vis[i]) ssum++;
		 } 	
		 if(ssum>sum) 
		 {
		 	cout<<"Red Alert: ";
		 	printf("City %d is lost!\n",lose);
		 	
		 }
		 else printf("City %d is lost.\n",lose);
		 sum=ssum;
	}
	if(tot==n) cout<<"Game Over."<<endl;
}
