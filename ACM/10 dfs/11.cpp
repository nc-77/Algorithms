#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int n,a[50][50],p[50][50];
void dfs(int x,int y)
{
    if(p[x][y]) return;
    if(x==n&&y==n) {
        p[x][y]=1;
        return;
    }
    if(a[x][y]==0) return;
    int nx=x+a[x][y],ny=y;
    if(nx>0&&nx<=n&&ny>0&&ny<=n) 
    {
        dfs(nx,ny);
        p[x][y]+=p[nx][ny];
    }
    nx=x;ny=y+a[x][y];
    if(nx>0&&nx<=n&&ny>0&&ny<=n) {
        dfs(nx,ny);
        p[x][y]+=p[nx][ny];
    }
}
signed main()
{
   //ios::sync_with_stdio(false);
   while(cin>>n&&n!=-1)
   {
       getchar();
       for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%1d",&a[i][j]);
       //for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) debug(a[i][j]);
       set0(p);
       dfs(1,1);
       cout<<p[1][1]<<endl;
   }
   //system("pause");
   return 0;
}
