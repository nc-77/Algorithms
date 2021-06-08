#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int dp[maxn][2],sum[maxn];
int s[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        scanf("%1d",&s[i]);
        for(int i=0;i<n;i++) dp[i][0]=dp[i][1]=0,sum[i]=0;
        sum[0]=s[0]==1;
        for(int i=1;i<n;i++) 
        {
            sum[i]=sum[i-1];
            if(s[i]==1) sum[i]++;
            //debug(sum[i]);
        }
        dp[0][0]=s[0]==1;
        dp[0][1]=s[0]==0;
        for (int i=1;i<n;i++)
        {
            dp[i][0]=min(dp[i-1][0],dp[i-1][1])+(s[i]==1);
            if(i-k>=0) dp[i][1]=dp[i-k][1]+sum[i-1]-sum[i-k]+(s[i]==0);
            else dp[i][1]=sum[i-1]+(s[i]==0);
            //debug(i),debug(dp[i][0]),debug(dp[i][1]);
        }
        cout<<min(dp[n-1][0],dp[n-1][1])<<endl;
   }
   //system("pause");
   return 0;
}
