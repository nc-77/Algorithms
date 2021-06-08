#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dr[105][105];
#define MAX_N 105
int par[MAX_N];
int high[MAX_N];//Ê÷µÄ¸ß¶È
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		high[i]=0;
	}
} 
int find(int x)
{
	if(par[x]==x)
	return x;
	else
	return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(high[x]<high[y])
	par[x]=y;
	else 
	{
		par[y]=x;
		if(high[x]==high[y]) high[x]++;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);	
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	init(n);
	while(m--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(z==1) unite(x,y);
		dr[x][y]=dr[y][x]=z;
	}
	while(k--)
	{
		int x,y;
		cin>>x>>y;
		if(same(x,y)&&dr[x][y]!=-1)  cout<<"No problem"<<endl;
		else if(!same(x,y)&&dr[x][y]!=-1)  cout<<"OK"<<endl;
		else if(same(x,y)&&dr[x][y]==-1) cout<<"OK but..."<<endl;
		else if(!same(x,y)&&dr[x][y]==-1) cout<<"No way"<<endl;
	}
}
