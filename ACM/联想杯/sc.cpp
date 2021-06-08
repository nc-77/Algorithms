#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int n,m,fa[maxn],cnt[maxn],ans;
struct node{
    int u,v;
    bool operator<(const node&t) const{
        if(max(u,v)<max(t.u,t.v)) return true;
        else if(max(u,v)==max(t.u,t.v))return  (min(u,v)<min(t.u,t.v));
        else return false;
    }
}e[maxn];
int find(int x)
{
    if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
// void unite(int x,int y)
// {
// 	x=find(x);
// 	y=find(y);
// 	if(x==y) return;
// 	par[x]=y;
// }
void kruskal()
{
    for(int i=1;i<=m;i++)
    { 
        int x=e[i].u,y=e[i].v;
        int xx=find(x),yy=find(y);
        if(xx==yy) continue;
        
        {
            fa[xx]=yy;
            cnt[x]++,cnt[y]++;
            ans=max(ans,max(cnt[x],cnt[y]));
        }
        
    }
}
signed main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        cin>>e[i].u>>e[i].v;
    }
    sort(e+1,e+m+1);
    kruskal();
    cout<<ans<<endl;
    return 0;
}