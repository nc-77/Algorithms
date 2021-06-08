#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=11;
int a[maxn][maxn][maxn][maxn];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
vector<int>key[maxn][maxn];
int last[maxn][maxn],vis[maxn][maxn];
int n,m,p;
struct  POS 
{
    int x,y,step,k;
}cur,nex;
bool check(POS p)
{
    int x=p.x,y=p.y;
    if(x>n||x<1||y>m||y<1) return false;
    if(vis[x][y]&&last[x][y]==p.k) return false;
    int g=a[cur.x][cur.y][x][y];
    if(g==-1) return false;
    if(g)
    {   int m=(p.k&(1<<(g-1)));
        if(m==0) 
        {return false;}
    }
    return true;
}
int bfs(){
    queue<POS>que;
    cur.x=cur.y=1;
    cur.step=cur.k=0;
    que.push(cur);
    while(!que.empty())
    {
        cur=que.front();
        que.pop();
        if(cur.x==n&&cur.y==m) return cur.step;
        for(int i=0;i<key[cur.x][cur.y].size();i++)
            cur.k=cur.k|(1<<(key[cur.x][cur.y][i]-1));
        last[cur.x][cur.y]=cur.k;
        vis[cur.x][cur.y]=1;
       // debug(cur.x),debug(cur.y),debug(cur.k),debug(cur.step);
        for(int i=0;i<4;i++)
        {
            nex.x=cur.x+dx[i],nex.y=cur.y+dy[i];
            nex.step=cur.step+1;
            nex.k=cur.k;
            if(check(nex))
            {
                que.push(nex);
               if(nex.x==n&&nex.y==m) return nex.step;
            }
        }
    }
    return -1;
}
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>m>>p;
   int k;cin>>k;
   for(int i=1;i<=k;i++)
   {
       int x,y,xx,yy,g;
       cin>>x>>y>>xx>>yy>>g;
       if(g==0) g=-1;
       a[x][y][xx][yy]=a[xx][yy][x][y]=g;

   }
   int s;cin>>s;
   for(int i=1;i<=s;i++) {
       int x,y,ss;
       cin>>x>>y>>ss;
       key[x][y].push_back(ss);
   }
   cout<<bfs()<<endl;
   //system("pause");
   return 0;
}
