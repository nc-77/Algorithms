#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
int n,m;
int vis[maxn],topo[maxn],t;
vector<int>g[maxn];
bool dfs(int u)
{
    vis[u]=-1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(vis[v]==-1) return false;
        else if(!vis[v]&&!dfs(v)) return false;
    }
    vis[u]=1;topo[t--]=u;
    return true;
}
bool toposort(){
    t=n;
    set0(vis);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        if(!dfs(i)) return false;
    }
    return true;
}
int main()
{
   while(cin>>n>>m)
   {    
       if(n==0&&m==0) break;
       for(int i=1;i<=n;i++) g[i].clear();
       set0(topo);
       while(m--)
       {
           int u,v;
           cin>>u>>v;
           g[u].push_back(v);
           
       }
       toposort();
           cout<<topo[1];
           for(int i=2;i<=n;i++)
           cout<<" "<<topo[i];
           cout<<endl;
   }
   
   //system("pause");
   return 0;
}
