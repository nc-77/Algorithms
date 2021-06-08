#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
char a[10][10];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int vis[15][15];
 int n,m,k,flag;
 bool judge(int x,int y)
 {
     if(!vis[x][y]&&x<=n&&x>0&&y>0&&y<=m&&a[x][y]!='X') return true;
     return false;
 }
void dfs(int sx,int sy,int tx,int ty,int step)
{
    //debug(sx),debug(sy),debug(step);
    if(flag||step>k) return;
    if(((abs(tx-sx)+abs(ty-sy))%2)!=((k-step)%2)) return;
    
    if(sx==tx&&sy==ty&&step==k)
    {
        flag=1;
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        int nx=sx+dx[i],ny=sy+dy[i];
        if(judge(nx,ny))
        {
            vis[nx][ny]=1;
            //debug(nx),debug(ny);
            dfs(nx,ny,tx,ty,step+1);
            vis[nx][ny]=0;
        }
    }
}
int main()
{
  
   while(cin>>n>>m>>k&&n)
   {
       int sx=0,sy=0,tx=0,ty=0;
       set0(vis);
       for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
       {
           cin>>a[i][j];
           if(a[i][j]=='S')
           {
               sx=i;
               sy=j;
           }
           if(a[i][j]=='D')
           {
               tx=i;
               ty=j;
           }
       }
       flag=0;
       vis[sx][sy]=1;
       dfs(sx,sy,tx,ty,0);
       if(flag) puts("YES");
       else puts("NO");
   }
   //system("pause");
   return 0;
}
