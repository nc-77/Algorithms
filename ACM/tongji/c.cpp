#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=1e3+10;
int a[maxn],p[maxn],dp[maxn][maxn][2];
signed main()
{
   //ios::sync_with_stdio(false);
    int n;
    cin>>n;
    memset(dp,inf,sizeof(dp));
    for(int i=1;i<=n;i++) cin>>a[i];
    int pos;
    for(int i=1;i<=n;i++) {
        cin>>p[i];
        if(p[i]==0) pos=i;
    }
    dp[pos][pos][0]=dp[pos][pos][1]=0;
    for(int len=1;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(pos<i||pos>j) continue;
            if(dp[i+1][j][0]+a[i+1]-a[i]<=p[i]);
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+a[i+1]-a[i]);
            if(dp[i+1][j][1]+a[j]-a[i]<=p[i])
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+a[j]-a[i]);
            if(dp[i][j-1][0]+a[j]-a[i]<=p[j])
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+a[j]-a[i]);
            if(dp[i][j-1][1]+a[j]-a[j-1]<=p[j])
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+a[j]-a[j-1]);
        }
    int ans=min(dp[1][n][0],dp[1][n][1]);
    if(ans==inf) cout<<"-1"<<endl;
    else cout<<ans<<endl;
   //system("pause");
   return 0;
}
