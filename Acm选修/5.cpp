#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll dp[maxn],ans[maxn];
int main()
{
   int t;
   cin>>t;
   dp[0]=0;
   ans[1]=ans[2]=dp[1]=dp[2]=1;
   for(int i=3;i<=40;i++)
   {
      dp[i]=dp[i-1]+dp[i-2]*4;
      ans[i]=dp[i];
      if(i>=5) 
      {
         //debug(dp[i-4]);
         int x=dp[i-4];
         for(int j=i-4;j<=i;j++)
         dp[j]=dp[j]-x;
       
      }
      
   }
   while(t--)
   {
      int n;
      cin>>n;
      cout<<ans[n]<<endl;
   }
   //system("pause");
   return 0;
}
