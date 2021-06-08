#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e4+10;
int tot=-1,head[maxn],flow[maxn],dis[maxn],pre[maxn],l[maxn],vis[maxn],ansf,ansc,mc,a[maxn][maxn];
struct edge{int to,nex,w,f;}e[maxn];
void add(int u,int v,int w,int f){e[++tot]=edge{v,head[u],w,f};head[u]=tot;}
bool min_spfa(int s,int t)
{
    memset(dis,inf,sizeof(dis));
    set0(vis);
    pre[t]=dis[s]=0;vis[s]=1;flow[s]=inf;
    queue<int>que;
    que.push(s);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
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
                    // if(!que.empty()&&dis[v]<dis[que.front()])
                    // que.push_front(v);
                    // else que.push_back(v); 
                    que.push(v);
                }
            }
        }
    }
    return pre[t];
}
bool max_spfa(int s,int t)
{
    for(int i=0;i<=tot;i++) dis[i]=-inf;
    set0(vis);
    pre[t]=dis[s]=0;vis[s]=1;flow[s]=inf;
    queue<int>que;
    que.push(s);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=e[i].nex)
        {
            int v=e[i].to,f=e[i].f,w=e[i].w;
            if(w>0&&dis[v]<dis[u]+f)
            {
                dis[v]=dis[u]+f;
                pre[v]=u;l[v]=i;
                flow[v]=min(flow[u],w);
                if(!vis[v]) {
                    vis[v]=1;
                    // if(!que.empty()&&dis[v]<dis[que.front()])
                    // que.push_front(v);
                    // else que.push_back(v); 
                    que.push(v);
                }
            }
        }
    }
    return pre[t];
}
void mfmc(int s,int t,int flag)
{
    if(flag==1)
    while(min_spfa(s,t))
    {   
        ansf+=flow[t];
        ansc+=flow[t]*dis[t];
        for(int i=t;i!=s;i=pre[i])
        {   
            e[l[i]].w-=flow[t];
            e[l[i]^1].w+=flow[t];
        }
    }
    else{
        while(max_spfa(s,t))
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
}
int main()
{
   int n;
   cin>>n;
   memset(head,-1,sizeof(head));
   for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
       int f;
       cin>>f;
       add(i,j+n,1,f);
       add(j+n,i,0,-f);
   }
   int s=0,t=2*n+1;
   for(int i=1;i<=n;i++) add(s,i,1,0),add(i,s,0,0);
   for(int i=n+1;i<=n+n;i++) add(i,t,1,0),add(t,i,0,0);
    mfmc(s,t,1);cout<<ansc<<endl;
    for(int i=0;i<=tot;i+=2) e[i].w+=e[i^1].w,e[i^1].w=0;
    ansc=0;ansf=0;
    mfmc(s,t,0);cout<<ansc<<endl;
   return 0;
}
