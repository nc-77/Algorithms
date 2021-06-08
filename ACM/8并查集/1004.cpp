#include<bits/stdc++.h>
using namespace std;
#define maxn 1050
int par[maxn],a[maxn][maxn];
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
    
    while(cin>>n)
    {   
        init(n);
        int cnt=0;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;
             unite(x,y);
        }
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        {
            if(!same(i,j)) 
            es[++cnt].from=x,es[cnt].to=y,es[cnt].cost=a[i][j];
        }
        cout<<kruskal(n,cnt)<<endl;
    }
}