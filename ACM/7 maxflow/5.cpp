#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
struct edge{int to,cap,rev;};
vector<edge>g[maxn];
int level[maxn];
int iter[maxn];   //当前弧
void add(int from, int to, int cap)
{
	g[from].push_back(edge{to,cap,(int)g[to].size()});
	g[to].push_back(edge{from, 0, (int)g[from].size() - 1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int>que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front();que.pop();
        for(int i=0;i<g[v].size();i++)
        {
            edge &e=g[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<g[v].size();i++)
    {
        edge &e=g[v][i];
        if(e.cap>0&&level[v]<level[e.to])
        {	//debug(v),debug(e.to);
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
            
        }

    }
    if(!f) level[v]=-1; 
    return 0;
}
int maxflow(int s,int t)
{
    int flow=0;
    while(1)
    {
        bfs(s);
        if(level[t]<0) return flow;
        set0(iter);
        int f;
        while(f=dfs(s,t,inf))
            flow+=f;

    }
    return flow;
}
int s[maxn],e[maxn],t[maxn],d[maxn];
int main()
{
   int n,m;
   while(cin>>n>>m)
   {    int sum=0;
       int cnt=0;
       set0(s),set0(e),set0(t),set0(d);
       for(int i=0;i<=maxn;i++) g[i].clear();
       for(int i=1;i<=n;i++) 
       {    int x,y;
           cin>>s[i]>>x>>e[i]>>y;
           t[i]=x*y;
           add(0,i,t[i]);
           sum+=t[i];
           d[cnt++]=s[i],d[cnt++]=e[i];
       }
       sort(d,d+cnt);
       cnt=unique(d,d+cnt)-d;
       cnt--;
       int T=n+cnt+1;
       for(int i=0;i<cnt;i++)
       add(i+n+1,T,m*(d[i+1]-d[i]));
       for(int i=1;i<=n;i++)
        for(int j=0;j<cnt;j++)
        {
            if(s[i]<=d[j]&&e[i]>=d[j+1])
            add(i,j+n+1,t[i]);
        }
        int ans=maxflow(0,T);
        //debug(ans);
        if(ans==sum) 
        cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
   }
   return 0;
}
