#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int dis[505],p[505];
struct edge
{
    int to,cost,pay;
};
vector<edge>g[505];
void dijkstra(int st,int ed)
{
    memset(dis,0x3f,sizeof(dis));
    memset(p,0x3f,sizeof(p));
    dis[st]=p[st]=0;
    queue<int>que;
    que.push(st);
    while(!que.empty())
    {
        int cur=que.front();
        que.pop();
        for(int i=0;i<g[cur].size();i++)
        {
            edge e=g[cur][i];
            if(dis[e.to]>e.cost+dis[cur]){
                dis[e.to]=e.cost+dis[cur];
                que.push(e.to);
                 p[e.to]=p[cur]+e.pay;
            }
            else if(dis[e.to]==e.cost+dis[cur]){
                if(p[e.to]>p[cur]+e.pay)
                p[e.to]=p[cur]+e.pay;
            }
        }
    }
    cout<<dis[ed]<<" "<<p[ed];
}
int main()
{
   int n,m,s,d;
   cin>>n>>m>>s>>d;
   for(int i=0;i<m;i++)
   {
       int x,y,cost,pay;
       cin>>x>>y>>cost>>pay;
       g[x].push_back({y,cost,pay});
        g[y].push_back({x,cost,pay});
   }
   dijkstra(s,d);
   return 0;
}
