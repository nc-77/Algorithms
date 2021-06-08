#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int dp[250][250];
int main()
{
   //ios::sync_with_stdio(false);
  for(int i=0;i<=120;i++) dp[0][i]=1;
   for(int i=1;i<=120;i++)
   {
       for(int j=1;j<=120;j++)
       {
           if(i>=j)dp[i][j]=dp[i][j-1]+dp[i-j][j];
           else dp[i][j]=dp[i][i];
       }
       
   }
    
    
    int n;
    while(cin>>n)
    {
        cout<<dp[n][n]<<endl;
    }
   //system("pause");
   return 0;
}
