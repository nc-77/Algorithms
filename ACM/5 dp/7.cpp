#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
int dp[maxn][maxn];
int main()
{
   string s1,s2;
   while(cin>>s1>>s2)
   {    set0(dp);
       int n=s1.size();
       int m=s2.size();
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(s1[i]==s2[j]) dp[i+1][j+1]=dp[i][j]+1;
               else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
           }
       }
       cout<<dp[n][m]<<endl;
   }
   //system("pause");
   return 0;
}
