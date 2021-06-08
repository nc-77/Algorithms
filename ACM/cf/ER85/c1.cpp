#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
ll a[maxn],b[maxn],dp[maxn];
signed main()
{  ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      int n;
       cin>>n;
       int sum=0;
       for(int i=1;i<=n;i++) cin>>a[i]>>b[i],sum+=a[i];
       for(int i=0;i<=n+n;i++) dp[i]=0;
       for(int i=2;i<=n;i++) dp[i]=dp[i-1]+min(a[i],b[i-1]);
       dp[n+1]=dp[n]-min(a[2],b[1])+min(a[1],b[n]);
       for(int i=n+2;i<n+n;i++)
       {
          dp[i]=dp[i-1]-min(a[i-n+1],b[i-n])+min(a[i-n],b[i-n-1]);
       }
       ll ans=sum;
       for(int i=n;i<n+n;i++)
       {
          ans=min(ans,sum-dp[i]);
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
