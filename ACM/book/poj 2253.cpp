#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e2+10;
int n,flag;
double x[maxn],y[maxn];
int vis[maxn],par[maxn],high[maxn];
double jl(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
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
bool ok(double t)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(jl(x[i],y[i],x[j],y[j])<=t)
		unite(i,j);
	return same(1,2);
}
int main()
{	int cnt=1;
    //freopen("in.txt","r",stdin);
    while(cin>>n&&n)
    {	set0(x),set0(y);
    	for(int i=1;i<=n;i++)
    	cin>>x[i]>>y[i];
    	double l=0,r=jl(x[1],y[1],x[2],y[2]);
    	while(r-l>1e-6)
    	{	flag=0;
    		double mid=(r+l)/2;
    		init(n);
    		if(ok(mid))
    		r=mid;
    		else l=mid;
		}
		printf("Scenario #%d\n",cnt++);
		printf("Frog Distance = %.3f\n\n",l);
	}
}

