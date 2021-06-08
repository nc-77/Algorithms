#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int n,m,ans;
int vis[105][105];
char a[105][105];
int dx[]={1,-1,0,0,1,1,-1,-1},dy[]={0,0,1,-1,1,-1,1,-1};
void dfs(int x,int y)
{
    //debug(x),debug(y);
    vis[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=n&&ny>0&&ny<=m&&a[nx][ny]=='@'&&!vis[nx][ny]) 
        dfs(nx,ny);
    }
}
int main()
{
   while(cin>>n>>m&&n)
   {
       for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
       set0(vis);
       ans=0;
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<=m;j++)
           {
               if(vis[i][j]||a[i][j]=='*') continue;
               dfs(i,j);
               ans++;
           }
           
       }
       cout<<ans<<endl;
   }

   //system("pause");
   return 0;
}
