#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
char a[100][100];
bool check(int x,int y)
{
    if(a[x][y]=='B') {
        if(a[x+1][y]=='G'||a[x][y+1]=='G'||a[x-1][y]=='G'||a[x][y-1]=='G') return false;

    }
    if(a[x][y]=='G') {
        if(a[x+1][y]=='B'||a[x][y+1]=='B'||a[x-1][y]=='B'||a[x][y-1]=='B') return false;

    }
    return true;
}
 int n,m;
struct node {
    int x,y;
}cur,nex;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int vis[100][100];
int bfs(){
    set0(vis);
    queue<node>q;
    q.push({n,m});
    vis[n][m]=1;
    int res=0;
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(a[cur.x][cur.y]=='G') res++;
        for(int i=0;i<4;i++)
        {
            nex.x=cur.x+dx[i];
            nex.y=cur.y+dy[i];
            if(nex.x>n||nex.x<1||nex.y>m||nex.y<1||a[nex.x][nex.y]=='#'||vis[nex.x][nex.y]) continue;
            q.push({nex.x,nex.y});
            vis[nex.x][nex.y]=1;
        }
    }
    return res;
}
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      
       cin>>n>>m;
       set0(a);
       for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
       int flag=1;
       int g=0;
       for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(!check(i,j)) flag=0;
            if(a[i][j]=='G') g++;
         }

        if(!g) { puts("yes");continue;}
         if(flag==0) {
            puts("no");continue;
        }
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='B') {
                for(int k=0;k<4;k++){
                   if(a[i+dx[k]][j+dy[k]]=='.')
                    a[i+dx[k]][j+dy[k]]='#';
                }
                
            }
         }
        int x=bfs();
        if(a[n-1][m]=='B'||a[n][m-1]=='B'||x!=g) flag=0;
        if(flag) puts("yes");
        else cout<<"no"<<endl;
   }
   //system("pause");
   return 0;
}
