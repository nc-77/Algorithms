#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g[maxn];
int size[maxn],dis[maxn],par[maxn],vis[maxn];
void dfs(int u,int fa)
{
    size[u]=1;
    par[u]=fa;
    for(int i=0;i<g[u].size();i++)
    {
        int to=g[u][i];
        if(to==fa) continue;
        dis[to]=dis[u]+1;
        dfs(to,u);
        size[u]+=size[to];
    }
}
struct node
{
    int id,dis;
    friend bool operator < (node x, node y)    
    {    
        return x.dis < y.dis;    //重载小于号使得小的先出队列    
    }   
};

signed main()
{ios::sync_with_stdio(false);
   int n,k;
   cin>>n>>k;
   dis[0]=-1;
   for(int i=1;i<n;i++) 
   {
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs(1,0);
   priority_queue <node,vector<node>,less<node> >q;
   for(int i=1;i<=n;i++)
   {
       size[i]--;
       if(g[i].size()==1)
       {
            q.push({i,dis[i]-size[i]});
            vis[i]=1;
       }
      
       
       //debug(i),debug(dis[i]),debug(size[i]);
   }
   int ans=0,cnt=0;
   while(!q.empty())
   {    
       node mx=q.top();
       q.pop();
      // debug(mx.id),debug(mx.dis);
      
       ans+=mx.dis;
       cnt++;
       if(cnt==k) break;
      if(!vis[par[mx.id]]) q.push({par[mx.id],dis[par[mx.id]]-size[par[mx.id]]});
       vis[par[mx.id]]=1;
       
   }
   //system("pause");
   cout<<ans<<endl;
   return 0;
}
