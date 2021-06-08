#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
const int mod=1e9+7;
int dp[maxn][maxn];
map<char,int>last;
int main()
{
   int n,k;
   string s;
   cin>>n>>k>>s;
   s=" "+s;
  for(int i=0;i<=n;i++) dp[i][0]=1;
  for(int i=1;i<=n;i++)
  {     
      for(int j=1;j<=i;j++)
      {     if(j==i) 
            {dp[i][j]=1;continue;}
          dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%mod;
          if(last[s[i]])dp[i][j]=((dp[i][j]-dp[last[s[i]]-1][j-1])%mod+mod)%mod;
          dp[i][j]=dp[i][j]%mod;
      }
      last[s[i]]=i;
  }
  cout<<dp[n][k]<<endl;
   //system("pause");
   return 0;
}
