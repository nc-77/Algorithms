#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
int dp[maxn][maxn],a[maxn][maxn];
int main()
{
   int n,k;
   while(cin>>n>>k)
   {
       set0(dp);
       for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) cin>>a[i][j],dp[i][j]=inf;
       int ans=inf;
       for(int i=1;i<=k;i++) dp[1][i]=0;
       for(int i=2;i<=n;i++)
        for(int j=1;j<=k;j++)
            for(int q=1;q<=k;q++)
        dp[i][j]=min(dp[i][j],dp[i-1][q]+abs(a[i-1][q]-a[i][j]));
    for(int i=1;i<=k;i++)
    ans=min(ans,dp[n][i]);
    
    cout<<ans<<endl;
   }
   return 0;
}
