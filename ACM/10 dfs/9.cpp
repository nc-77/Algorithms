#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int n,k,a[105][105],dp[105][105],ans;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
void dfs(int x,int y)
{
    if(dp[x][y]) return;
    dp[x][y]=a[x][y];
    for(int i=0;i<4;i++)
        for(int j=1;j<=k;j++)
        {
            int nx=x+dx[i]*j,ny=y+dy[i]*j;
            if(nx>=1&&nx<=n&&ny>=0&&ny<=n&&a[x][y]<a[nx][ny])
            {
                dfs(nx,ny);
                dp[x][y]=max(dp[x][y],dp[nx][ny]+a[x][y]);
            }
            
        }
    
}
int main()
{
   ios::sync_with_stdio(false);
   while(cin>>n>>k)
   {
       if(n==-1&&k==-1) break;
       for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
       set0(dp);
       dfs(1,1);
       cout<<dp[1][1]<<endl;
   }
   //system("pause");
   return 0;
}
