#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int tot=-1,head[maxn],flow[maxn],dis[maxn],pre[maxn],l[maxn],vis[maxn],ansf,ansc;
struct edge{int to,nex,w,f;}e[maxn];
char a[105][105];
void add(int u,int v,int w,int f){e[++tot]=edge{v,head[u],w,f};head[u]=tot;}
bool spfa(int s,int t)
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
                if(!vis[v]) {que.push(v);vis[v]=1;}
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
struct pos
{
    int x,y;
};
vector<pos>p,h;
int main()
{
   int n,m,s,t;
   while(~scanf("%d %d",&n,&m))
   {    ansf=ansc=0;
       if(!n) break;
       memset(head,-1,sizeof(head));
       p.clear();h.clear();
       tot=-1;
       for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
        {
        if(a[i][j]=='m') p.push_back({i,j});
        else if(a[i][j]=='H') h.push_back({i,j});}
        int sum=p.size();
        s=2*sum+1,t=2*sum+2;
        for(int i=0;i<p.size();i++)
            for(int j=0;j<h.size();j++)
            {
                int d=abs(p[i].x-h[j].x)+abs(p[i].y-h[j].y);
                add(i,sum+j,1,d);
                add(sum+j,i,0,-d);
            }
        for(int i=0;i<p.size();i++)
        {
            add(s,i,1,0);
            add(i,s,0,0);
        }
        for(int i=0;i<h.size();i++)
        {
            add(sum+i,t,1,0);
            add(t,sum+i,0,0);
        }
        mfmc(s,t);
        cout<<ansc<<endl;
   }
   

   return 0;
}
