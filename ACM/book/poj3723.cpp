#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define inf 0x3f3f3f3f
#define MAX_N 50010
using namespace std;
int m,n,r;
struct edge
{
	ll form,to,cost;
}es[50000+10];
bool cmp(edge e1,edge e2)
{
	return e1.cost>e2.cost;
}
int par[MAX_N];
int high[MAX_N];//Ê÷µÄ¸ß¶È
void init(int n)
{
	for(int i=0;i<n;i++)
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
int kruskal()
{
	sort(es,es+r,cmp);
	init(n+m);
	int res=0;
	for(int i=0;i<r;i++)
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
	int t;
	cin>>t;
	while(t--)
	{	memset(es,0,sizeof(es));
		scanf("%d%d%d", &n, &m, &r);
		for(int i=0;i<r;i++)
		{
			scanf("%d%d%d", &es[i].to, &es[i].form, &es[i].cost);
			es[i].to+=m;
	
		}
		printf("%d\n", (n + m) * 10000 - kruskal());
	}
 } 
