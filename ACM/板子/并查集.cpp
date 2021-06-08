#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
int par[maxn];
void init(int n){
	for(int i=1;i<=n;i++) par[i]=i;
} 
int find(int x)
{
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	par[x]=y;
}
bool same(int x,int y){
	return find(x)==find(y);	
}
int kruskal()
{
	sort(es+1,es+E+1,cmp);
	init(maxn);
	int res=0;
	for(int i=1;i<=E;i++)
	{
		if(!same(es[i].form,es[i].to))
		{
			res+=es[i].cost;
			unite(es[i].form,es[i].to);
		}
	}
	return res;
}
int main()
{
	int n,m;
	int x,y,z;
	cin>>n>>m;
	init(n);
	for(int i=1;i<=m;i++) 
	{
		cin>>z>>x>>y;
		if(z==1) unite(x,y);
		else 
		{
			if(same(x,y)) puts("Y");
			else cout<<"N"<<endl;
		}

	}
}

