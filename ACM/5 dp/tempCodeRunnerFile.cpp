#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
ll a[maxn],dp[maxn][maxn];
int main()
{
   int n,k;
   while(cin>>n>>k)
   {
       for(int i=1;i<=n;i++) cin>>a[i];
       sort(a+1,a+n+1);
        for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=inf;
        dp[0][0]=0;
        for(int i=2;i<=n;i++)
            for(int j=1;j<=i/2;j++)
            {
                dp[i][j]=min((a[i]-a[i-1])*(a[i]-a[i-1])+dp[i-2][j-1],dp[i-1][j]);
            }
        cout<<dp[n][k]<<endl;
   }
   //system("pause");
   return 0;
}
