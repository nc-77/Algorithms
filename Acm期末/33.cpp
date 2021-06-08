#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int dp[maxn];
int main()
{
   int n;
   while(cin>>n){
       for (int i=0;i<n;i++){
           dp[i]=0;
       }
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=0;
        if(n==1) cout<<a[0]<<endl;
        else if(n==2) cout<<max(a[0],a[1])<<endl;
        else if(n==3) cout<<max(a[0]+a[2],a[1])<<endl;
        else{
            dp[0]=a[0];
            dp[1]=a[1];
            dp[2]=a[0]+a[2];
            for(int i=3;i<n;i++){
                dp[i]=a[i]+max(dp[i-2],dp[i-3]);
                ans=max(ans,dp[i]);
            }
            cout<<ans<<endl;
        }
   }
   return 0;
}
