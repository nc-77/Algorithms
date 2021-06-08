#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))

using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
struct edge{int to,cap,rev;};
vector<edge>g[maxn];
vector<int>r[maxn];
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
int n,e,need[maxn];
int s=0,t,sum=0;
bool check(int x)
{
    for(int i=s;i<=t;i++) g[i].clear();
    for(int i=1;i<=n;i++)
    {
        add(s,i,need[i]);
        for(int j=0;j<r[i].size();j++)
        add(i,n+r[i][j],inf);
    }
    for(int i=n+1;i<=n+7;i++)
    {
        int m=x/7;
        if(i-n<=x%7) add(i,t,e*(m+1));
        else add(i,t,e*m);
        
    }
    int ans=maxflow(s,t);
   // debug(ans);
    if(sum==ans) return true;
    else return false;
}
signed main()
{
   ios::sync_with_stdio(false);
   cin>>n>>e;
  t=n+8;
   for(int i=1;i<=n;i++)
   {
       int sq;
        cin>>need[i]>>sq;
        sum+=need[i];
    
       while(sq--)
       {
           int d;
           cin>>d;
           r[i].push_back(d);
       }
   }
   int l=0,r=1e9,mid;

   while(r-l>1)
   {
       mid=(l+r)/2;
       //debug(mid),debug(l),debug(r);
        
       if(check(mid)) r=mid;
       else l=mid;
       
   }
 cout<<r<<endl;
   //system("pause");
   return 0;
}
