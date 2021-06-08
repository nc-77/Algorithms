#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn],dp[maxn][2],f[maxn];
int vis[maxn];
signed main()
{
   int n,c;
   cin>>n>>c;

   for(int i=1;i<n;i++) cin>>a[i];
   for(int i=1;i<n;i++) cin>>b[i];
   set0(dp);
   dp[1][1]=c;
   for(int i=2;i<=n;i++)
   {
      dp[i][0]=min(dp[i-1][0]+a[i-1],dp[i-1][1]+a[i-1]);
      dp[i][1]=min(dp[i-1][0]+c+b[i-1],dp[i-1][1]+b[i-1]);
   }
   for(int i=1;i<=n;i++)
   cout<<min(dp[i][0],dp[i][1])<<" ";
   //system("pause");
   return 0;
}
