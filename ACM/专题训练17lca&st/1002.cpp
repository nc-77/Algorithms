#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e4+10;
struct edge
{
    int to,cost;
};
vector<edge>g[maxn];
int l[maxn],p[maxn][25],dis[maxn],par[maxn],f[maxn];
int find(int x){
    if(x==par[x]) return x;
    else return par[x]=find(par[x]);
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    else par[x]=y;
}
void dfs(int u,int fa){
    f[u]=fa;
    for(int i=0;i<g[u].size();i++){
        int to=g[u][i].to,cost=g[u][i].cost;
        if(to==fa) continue;
        l[to]=l[u]+1;
        dis[to]=dis[u]+cost;
        dfs(to,u);
    }
}
void lca(int n){
    memset(p,-1,sizeof(p));
    for(int i=1;i<=n;i++) p[i][0]=f[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i<=n;i++){
            if(p[i][j-1]!=-1)
            p[i][j]=p[p[i][j-1]][j-1];
        }
}
int query(int u,int v){
    if(l[u]<l[v]) swap(u,v);
    for(int i=20;i>=0;i--){
        if(l[p[u][i]]>=l[v]) u=p[u][i];
    }
    if(u==v) return u;
    for(int i=20;i>=0;i--){
        if(p[u][i]!=-1&&p[u][i]!=p[v][i]){
            u=p[u][i];v=p[v][i];
        }
        
    }
    //debug(u),debug(v);
    return f[u];
}
int main()
{
  // ios::sync_with_stdio(false);
   int n,m,q;
  while(~scanf("%d%d%d",&n,&m,&q))
  {
      for(int i=0;i<=n;i++) g[i].clear(),par[i]=i,f[i]=l[i]=dis[i]=0;
      while(m--)
      {
          int u,v,c;
          scanf("%d%d%d",&u,&v,&c);
          g[u].push_back({v,c});
          g[v].push_back({u,c});
          unite(u,v);
      }
      for(int i=1;i<=n;i++){
          if(f[i]==0){
              l[i]=1;
              dfs(i,0);
          }
      }
      //for(int i=1;i<=n;i++) debug(i),debug(l[i]),debug(dis[i]),debug(f[i]);
      lca(n);
      while(q--){
          int u,v;
          scanf("%d%d",&u,&v);
          if(find(u)!=find(v)){
              printf("Not connected\n");
          }
          else {
              int zx=query(u,v);
              //debug(zx);
              int ans=dis[u]+dis[v]-2*dis[zx];
              printf("%d\n",ans);
          }
      }
  } 
   //system("pause");
   return 0;
}
