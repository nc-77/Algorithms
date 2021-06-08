#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
int par[maxn];
struct node
{
    int from,to;
	double cost;
}es[maxn];
bool cmp(node x,node y)
{
    return x.cost<y.cost;
}
double x[maxn],y[maxn];
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
double kruskal(int n,int E)
{
	sort(es+1,es+E+1,cmp);
	double res=0;
	for(int i=1;i<=E;i++)
	{
		if(!same(es[i].from,es[i].to))
		{
			res+=es[i].cost;
			unite(es[i].from,es[i].to);
		}
	}
	return res;
}
int main()
{	
    int n;
    int t;
    cin>>t;
    while(t--)
    {   cin>>n;
        int cnt=0;
        init(n);
        for(int i=1;i<=n;i++)
        {
			cin>>x[i]>>y[i];
        }
      
       	for(int i=1;i<=n;i++)
       		for(int j=i+1;j<=n;j++)
       		{
       			double jl=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
       			jl=sqrt(jl);
       			if(jl>=10.000000&&jl<=1000.000001) 
       			es[++cnt].from=i,es[cnt].to=j,es[cnt].cost=jl*100;
			   }
			   double res=kruskal(n,cnt);
			   int ans=0;
			for(int i=1;i<=n;i++)
			{
				if(par[i]==i) ans++;
			}
			if(ans!=1) printf("oh!\n");
			else printf("%.1f\n",res);
    }
}