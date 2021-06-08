#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define PII pair<int,int> 
using namespace std;
struct edge
{
    int to,cost;
};
vector<edge>g[1050];
int vis[1050],d[1050];
int n,m;
int Prim()
{
    priority_queue<PII,vector<PII>,greater<PII>>que;
    que.push(PII(0,1));
    int ans=0;
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    while(!que.empty())
    {
        int cur=que.top().second;
        que.pop();
        if(vis[cur]) continue;
        vis[cur]=1;
        ans+=d[cur];
        for(int i=0;i<g[cur].size();i++)
        {
            int to=g[cur][i].to;
            if(!vis[to])
            {
                 d[to]=min(d[to],g[cur][i].cost);
                que.push(PII(d[to],to));
            }
           
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]) return -1;
    }
    return ans;
}
int main()
{
   
   cin>>n>>m;
   while(m--)
   {
       int x,y,cost;
       cin>>x>>y>>cost;
       g[x].push_back({y,cost});
       g[y].push_back({x,cost});
   }
   cout<<Prim()<<endl;
   return 0;
}
