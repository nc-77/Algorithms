#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int tot=-1,head[maxn],flow[maxn],dis[maxn],pre[maxn],l[maxn],vis[maxn],ansf,ansc;
struct edge{int to,nex,w,f;}e[maxn];
void add(int u,int v,int w,int f){e[++tot]=edge{v,head[u],w,f};head[u]=tot;}
bool spfa(int s,int t)
{
    memset(dis,inf,sizeof(dis));
    set0(vis);
    pre[t]=dis[s]=0;vis[s]=1;flow[s]=inf;
    deque<int>que;
    que.push_back(s);
    while(!que.empty())
    {
        int u=que.front();
        que.pop_front();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].nex)
        {
            int v=e[i].to,f=e[i].f,w=e[i].w;
            if(w>0&&dis[v]>dis[u]+f)
            {
                dis[v]=dis[u]+f;
                pre[v]=u;l[v]=i;
                flow[v]=min(flow[u],w);
                if(!vis[v]) {
                    vis[v]=1;
                    if(!que.empty()&&dis[v]<dis[que.front()])
                    que.push_front(v);
                    else que.push_back(v); 
                }
            }
        }
    }
    return pre[t];
}
void mfmc(int s,int t)
{
    while(spfa(s,t))
    {   
        ansf+=flow[t];
        ansc+=flow[t]*dis[t];
        for(int i=t;i!=s;i=pre[i])
        {   
            e[l[i]].w-=flow[t];
            e[l[i]^1].w+=flow[t];
        }
    }
}
int main()
{
   int n,m,s,t;
   cin>>n>>m>>s>>t;
   memset(head,-1,sizeof(head));
   for(int i=1;i<=m;i++)
   {
       int u,v,w,f;
       cin>>u>>v>>w>>f;
       add(u,v,w,f);
       add(v,u,0,-f);
   }
   mfmc(s,t);
   cout<<ansf<<" "<<ansc<<endl;
   return 0;
}
