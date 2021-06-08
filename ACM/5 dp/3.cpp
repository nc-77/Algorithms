#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
ll dp[maxn],a[maxn];
int main()
{
   int n;
   while(cin>>n&&n)
   {
       set0(dp);
       for(int i=1;i<=n;i++) cin>>a[i],dp[i]=a[i];
       ll ans=dp[1];
       for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i])
            dp[i]=max(dp[i],dp[j]+a[i]);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
