#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
map<string,int>mp;
vector<int>g[maxn];
int dis[maxn],p[maxn][35],par[maxn];
void dfs(int u,int fa){
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
    int log=log2(dis[u]);
    for(int i=log;i>=0;i--)
        if(dis[u]-(1<<i)>=dis[v]) u=p[u][i];
    if(u==v) return u;
    for(int i=log;i>=0;i--){
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
       mp.clear();
       for(int i=1;i<=n;i++) g[i].clear(),par[i]=-1;
       int cnt=0;
       for(int i=1;i<n;i++) {
           string s1,s2;
           cin>>s1>>s2;
            if(!mp[s1])mp[s1]=++cnt;
            if(!mp[s2])mp[s2]=++cnt;
            g[mp[s1]].push_back(mp[s2]);
            g[mp[s2]].push_back(mp[s1]);
            par[mp[s1]]=mp[s2];
       }
       int s=0;
       for(int i=1;i<=n;i++) {
           if(par[i]==-1) {
               s=i;
               break;
           }
       }
       lca(n,s);
       while(m--)
       {
           string s1,s2;
           int u,v;
           cin>>s1>>s2;
            u=mp[s1],v=mp[s2];
           int zx=query(u,v);
           int  ans=dis[u]-dis[zx]+1;
           if(zx==v) ans--;
           cout<<ans<<endl;
       }
   }
   //system("pause");
   return 0;
}
