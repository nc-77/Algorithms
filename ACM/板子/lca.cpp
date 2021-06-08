#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=5e5+10;
vector<int>g[maxn];
int dis[maxn],p[maxn][25],par[maxn];
void dfs(int u,int fa){
    par[u]=fa;
    for(int i=0;i<g[u].size();i++)
    {
        if(g[u][i]==fa) continue;
        dis[g[u][i]]=dis[u]+1;
        dfs(g[u][i],u);
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
    if(dis[u]<dis[v])  swap(u,v);
    //int log=log2(dis[u]);
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
   int n,m,s;
   cin>>n>>m>>s;
   for(int i=1;i<n;i++){
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   lca(n,s);
   while(m--)
   {
       int u,v;
       cin>>u>>v;
      cout<<query(u,v)<<endl;
   }
   //system("pause");
   return 0;
}
