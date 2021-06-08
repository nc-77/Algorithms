#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1e6+10;
int dp[maxn],a[maxn];
int main()
{
   int n;
   cin>>n;
   int ans=-1;
   for(int i=1;i<=n;i++) cin>>a[i];
   int l=1,r=n;
   int tl=1,tr=1;
   for(int i=1;i<=n;i++)
   {
       if(dp[i-1]>=0)
       {
           dp[i]=dp[i-1]+a[i];
           tr=i;
       }
       else{
           dp[i]=a[i];
           tl=tr=i;
       }
       if(dp[i]>ans)
       {
           ans=dp[i];
            r=tr;
            l=tl;
       }
   }
   if(ans<0) cout<<0<<" "<<a[1]<<" "<<a[n]<<endl;
   else cout<<ans<<" "<<a[l]<<" "<<a[r]<<endl;
   //system("pause");
   return 0;
}
