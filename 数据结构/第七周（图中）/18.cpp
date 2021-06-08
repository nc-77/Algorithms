#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int inf=0x3f3f3f3f;
int dp[105][105];
int main()
{
   int n,m;
   cin>>n>>m;
   memset(dp,0x3f,sizeof(dp));
   while(m--)
   {
       int x,y,cost;
       cin>>x>>y>>cost;
       dp[x][y]=dp[y][x]=cost;
   }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)+9
        {
            if(i==j) dp[i][j]=0;
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
    int id=0,ans=inf;
    for(int i=1;i<=n;i++)
    {
        int flag=1,mx=0;
        for(int j=1;j<=n;j++)
        {
            if(dp[i][j]==inf) {
                flag=0;
                break;
            }
            mx=max(dp[i][j],mx);
        }
        if(flag&&mx<ans) {
            ans=mx;
            id=i;
        }
    }
    if(id){
        cout<<id<<" "<<ans<<endl;
    }
    else puts("0");
   return 0;
}
