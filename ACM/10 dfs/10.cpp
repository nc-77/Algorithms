#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define PII pair<int,int> 
using namespace std;
//define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
int n,m,dis[maxn],p[maxn];
struct edge{int to,cost;};
vector<edge>g[maxn];
void dijk(int s)
{
    priority_queue<PII,vector<PII>,greater<PII> >que;
    memset(dis,inf,sizeof(dis));
    dis[s]=0;
    que.push(PII(0,s));
    while(!que.empty())
    {
        PII p=que.top();
        que.pop();
        int v=p.second;
        if(dis[v]<p.first) continue;
        for(int i=0;i<g[v].size();i++)
        {
            edge e=g[v][i];
            if(dis[e.to]>dis[v]+e.cost)
            {
                dis[e.to]=dis[v]+e.cost;
                que.push(PII(dis[e.to],e.to));
            }
        }
    }
}
void dfs(int u)
{
    if(p[u]) return;
    if(u==2)
    {
        p[u]=1;
        return;
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].to;
        if(dis[v]>=dis[u]) continue;
        dfs(v);
        p[u]+=p[v];
    }
}
int main()
{
    ios::sync_with_stdio(false);
   while(cin>>n&&n)
   {
       cin>>m;
       for(int i=1;i<=n;i++) g[i].clear();
       for(int i=1;i<=m;i++)
       {
           int u,v,cost;
           cin>>u>>v>>cost;
           g[u].push_back({v,cost});
           g[v].push_back({u,cost});
       }
       dijk(2);
       //for(int i=1;i<=n;i++) debug(dis[i]);
       set0(p);
       dfs(1);
       cout<<p[1]<<endl;
   }
   //system("pause");
   return 0;
}
