#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1e3+10;
int v[maxn],w[maxn];
int f[maxn];
int dp[maxn][maxn];
int main()
{
    int m,n;
   while(cin>>m>>n){
       if(m==-1&&n==-1) break;
       memset(f,-inf,sizeof(f));
        f[0]=0;
        for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
        // for(int i=1;i<=n;i++)
        //     for(int j=m;j>=v[i];j--)
        //     f[j]=max(f[j],f[j-v[i]]+w[i]);
        // if(f[m]<0) puts("-1");
        // else cout<<f[m]<<endl;
        memset(dp,-inf,sizeof(dp));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++)
            for(int j=v[i];j<=m;j++){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);
            }
        if(dp[n][m]<0) puts("-1");
         else cout<<dp[n][m]<<endl;
   }
   return 0;
}
