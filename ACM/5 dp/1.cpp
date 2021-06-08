#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
int a[maxn][maxn],dp[maxn][maxn];
int main()
{
   
   //system("pause");
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       set0(dp);
       for(int i=1;i<=n;i++)for(int j=1;j<=i;j++) scanf("%d",&a[i][j]);
       
       dp[1][1]=a[1][1];
       int ans=a[1][1];
       for(int i=2;i<=n;i++)
       {
           for(int j=1;j<=i;j++)
           {
               if(j==1)dp[i][j]=dp[i-1][j]+a[i][j];
               else if(j==i) dp[i][j]=dp[i-1][j-1]+a[i][j];
               else dp[i][j]=max(dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j]);
               ans=max(ans,dp[i][j]);
           }
       }
       cout<<ans<<endl;
   }
   return 0;
}
