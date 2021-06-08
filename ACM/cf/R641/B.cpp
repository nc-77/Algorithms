#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],dp[maxn];
signed main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i],dp[i]=1;
       int ans=1;
       
       for(int i=2;i<=n;i++)
       {
           int x=sqrt(i);
           //debug(x);
           for(int j=1;j<=x;j++)
           {
               if(i%j!=0) continue;
               int k=i/j;
               if(j==1) {
                   if(a[i]>a[1]) dp[i]=max(dp[i],dp[1]+1);
                   continue;
               }
               if(k==j&&a[i]>a[j]) dp[i]=max(dp[i],dp[k]+1); 
               else if(k!=j){
                   if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
                   if(a[i]>a[k]) dp[i]=max(dp[i],dp[k]+1);
               }
              
           }
            // debug(i),debug(dp[i]);
           ans=max(ans,dp[i]);
            
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
