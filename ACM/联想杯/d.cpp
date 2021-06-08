#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int par[maxn],n,m,f[maxn],D[maxn];
struct node{
    int from,to;
    bool operator<(const node &t){
        if(max(from,to)==max(t.from,t.to)) 
            return min(from,to)<min(t.from,t.to);
        else return max(from,to)<max(t.from,t.to);
    }
}es[maxn];
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
void kruskal()
{
	sort(es+1,es+m+1);
	init(maxn);
	//int res=0;
	for(int i=1;i<=m;i++)
	{
		if(!same(es[i].from,es[i].to))
		{
			//res+=es[i].d;
			unite(es[i].from,es[i].to);
            D[es[i].from]++;
            D[es[i].to]++;
		}
	}
	//return res;
}
signed main()
{
   //ios::sync_with_stdio(false);
   cin>>n>>m;
   
   for(int i=1;i<=m;i++)
   {
       cin>>es[i].from>>es[i].to;
   }
   kruskal();
   int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,D[i]);
    }
    cout<<ans<<endl;
   //system("pause");
   return 0;
}
