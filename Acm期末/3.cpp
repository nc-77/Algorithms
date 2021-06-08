#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int dp[maxn][2];
int main()
{
   int n;
   while(cin>>n){
        memset(dp,0,sizeof(dp));
            for(int i=0;i<n;i++){
            cin>>a[i];
        }
        dp[0][0]=0;
        dp[0][1]=a[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+a[i]);

        }
        cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
   }
   
   

   return 0;
}
