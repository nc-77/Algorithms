#include<bits/stdc++.h>
using namespace std;
#define maxn 50010
int par[maxn];
struct node
{
    int from,to,cost;
}es[maxn];
bool cmp(node x,node y)
{
    return x.cost<y.cost;
}
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
int kruskal(int n,int E)
{
	sort(es+1,es+E+1,cmp);
	init(n);
	int res=0;
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
    
    while(cin>>n&&n)
    {   
        int m=n*(n-1)/2;
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            int x,y,c,o;
            cin>>x>>y>>c>>o;
            if(!o)es[++cnt].from=x,es[cnt].to=y,es[cnt].cost=c;
            else unite(x,y);
        }
        cout<<kruskal(n,cnt)<<endl;
    }
}