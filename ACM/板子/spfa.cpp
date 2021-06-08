#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct node{
    int v,w,nex;
}e[maxn];
int n,m,head[maxn],num,dis[maxn],vis[maxn];
void add(int u,int v,int w)
{
    e[++num].nex=head[u];
    e[num].v=v;e[num].w=w;
    head[u]=num;
}
void spfa(int s)
{   queue<int>que;
    memset(dis,inf,sizeof(dis));
    vis[s]=1;dis[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int u=que.front();que.pop();
        vis[u]=0;
        for(int i=head[u];i;i=e[i].nex)
        {
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                if(!vis[v])
                {
                    que.push(v);
                    vis[v]=1;
                }
            }
        }
    }
}
int main()
{
   int u,v,c,s;
   cin>>n>>m>>s;
   for(int i=1;i<=m;i++)
   {
       cin>>u>>v>>c;
       add(u,v,c);
   }
   spfa(s);
   for(int i=1;i<=n;i++) 
   {
       if(dis[i]==inf) cout<<2147483647<<" ";
       else cout<<dis[i]<<" ";}
   return 0;
}
