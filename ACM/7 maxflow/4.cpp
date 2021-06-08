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
        while(f=dfs(s,t,inf)>0)
            flow+=f;

    }
}
int n,m;
int fun(int x,int y)
{
    return (x-1)*m+y+1;
}
int main()
{
   int T;
   cin>>T;
   int cnt=1;
   while(T--)
   {
       int k;
       cin>>n>>k;
       string s;
       int sum=0;
       for(int i=1;i<=n;i++) 
       {
           cin>>s;
           m=s.size();
           for(int j=0;j<m;j++)
           {
               int id=(i-1)*m+j+1;
               add(id,id+n*m,s[j]-'0');//拆点
           }
           
       }
       for(int i=1;i<=n;i++)
       {
           cin>>s;
           for(int j=0;j<m;j++)
           {
               int id=(i-1)*m+j+1;
               if(s[j]=='L') add(0,id,1),sum++;
           }
       }
       int t=2*n*m+1;
       for(int i=n*m+1;i<t;i++)
       {    int id=i-n*m;
           int y=(id+m-1)%m+1;
           int x=(id-y)/m+1;
            if(x<=k||(n-x)<k||y<=k||(m-y)<k) add(i,t,inf);
       }
       for(int i=1;i<=n*m;i++)
       {
           int y=(i+m-1)%m+1;
           int x=(i-y)/m+1;
           for(int j=1;j<=n*m;j++)
           {
               if(i==j) continue;
               int yy=(j+m-1)%m+1;
                int xx=(j-yy)/m+1;
                if(fabs(yy-y)+fabs(xx-x)<=k) add(i+n*m,j,inf);
           }
       }
       int ans=maxflow(0,t);
//      debug(sum);
//      debug(ans);
       if(sum<=ans) 
       printf("Case #%d: no lizard was left behind.\n",cnt++);
        else if(sum-ans==1)printf("Case #%d: %d lizard was left behind.\n",cnt++,sum-ans);
     	else printf("Case #%d: %d lizards were left behind.\n",cnt++,sum-ans);
	 for(int i=0;i<=t;i++) g[i].clear();
   }
   
   return 0;
}
