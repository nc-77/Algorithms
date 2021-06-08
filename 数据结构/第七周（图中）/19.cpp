#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int n,flag;
double d;
const double  ISLAND=15.0/2;
int g[105][105];
int dis[105];
const int inf=0x3f3f3f3f;
struct node
{
    double x,y;
    bool operator<(node &t){
        return (x*x+y*y )< (t.x*t.x+t.y*t.y );
    }
}p[105];
int pre[105];
bool fjump(int i){
	return sqrt( p[i].x*p[i].x+p[i].y*p[i].y )<=d+ISLAND;
}
bool jump(int x,int y){
	return sqrt( (p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)* ( p[x].y-p[y].y) )<=d;
}
bool judge(int i){
	return (abs(p[i].x)>=50-d||abs(p[i].y)>=50-d);
}
int vis[105];
int dijkstra(int n)
{
    memset(pre,-1,sizeof(pre));
    memset(dis,0x3f,sizeof(dis));
    dis[0]=0;
    queue<int>que;
    que.push(0);
    vis[0]=1;
    while(!que.empty())
    {
        int cur=que.front();
        que.pop();
        for(int i=0;i<=n+1;i++)
            {
                if(g[cur][i]!=-1&&!vis[i]){
                    que.push(i);
                    dis[i]=dis[cur]+1;
                    vis[i]=1;
                    pre[i]=cur;
                }
            }
    }
    return dis[n+1];
}
void printpath(int st){
    if(st==0) return;
    printpath(pre[st]);
    if(st!=n+1)cout<<p[st].x<<" "<<p[st].y<<endl;
    
}
int main()
{
   cin>>n>>d;
   memset(g,-1,sizeof(g));
   for(int i=1;i<=n;i++)
   {
       cin>>p[i].x>>p[i].y;
   }
   sort(p+1,p+n+1);
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(jump(i,j)) g[i][j]=1;
    }
    for(int i=0;i<=n;i++){
        if(judge(i)&&i) g[i][n+1]=g[n+1][i]=1;
        if(fjump(i)&&i){
           g[0][i]=g[i][0]=1;
       }
        g[i][i]=0;
    }
    g[n+1][n+1]=0;
    if(d>=42.5) g[0][n+1]=g[n+1][0]=1;
    int ans=dijkstra(n);
    if(ans!=inf){
        cout<<ans<<endl;
        printpath(n+1);
    }
    else cout<<0<<endl;
   return 0;
}
