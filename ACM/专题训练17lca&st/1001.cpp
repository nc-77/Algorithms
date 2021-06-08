#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=4e4+10;
struct edge
{
    int to,cost;
};

vector<edge>g[maxn];
int dis[maxn],p[maxn][35],par[maxn],d[maxn];
void dfs(int u,int fa){
    par[u]=fa;
    for(int i=0;i<g[u].size();i++)
    {
        int to=g[u][i].to,cost=g[u][i].cost;
        if(to==fa) continue;
        dis[to]=dis[u]+1;
        d[to]=d[u]+cost;
        dfs(to,u);
    }
}
void lca(int n,int s){
    memset(dis,0,sizeof(dis));
    dis[s]=1;dfs(s,0);
    memset(p,-1,sizeof(p));
    for(int i=1;i<=n;i++) p[i][0]=par[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++){
            if(p[i][j-1]!=-1)
            p[i][j]=p[p[i][j-1]][j-1];
        }
}
int query(int u,int v){
    if(dis[u]<dis[v]) swap(u,v);
    for(int i=20;i>=0;i--)
        if(dis[p[u][i]]>=dis[v]) u=p[u][i];
    if(u==v) return u;
    for(int i=20;i>=0;i--){
        if(p[u][i]!=-1&&p[u][i]!=p[v][i]){
            u=p[u][i];v=p[v][i];
        }
    }
    return par[u];
}
int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       for(int i=1;i<=n;i++) g[i].clear(),d[i]=0;
       for(int i=1;i<n;i++) {
           int u,v,c;
            cin>>u>>v>>c;
            g[u].push_back({v,c});
            g[v].push_back({u,c});
       }
        lca(n,1);
        while(m--){
            int u,v;
            cin>>u>>v;
            int zx=query(u,v);
            int ans=d[u]-d[zx]+d[v]-d[zx];
            cout<<ans<<endl;
        }
   }
   //system("pause");
   return 0;
}
