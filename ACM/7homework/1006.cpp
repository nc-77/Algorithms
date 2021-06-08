#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int v[maxn],w[maxn],dp[maxn];
int main()
{   int n;
   while(cin>>n)
   {    set0(dp);
       for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
       int m;cin>>m;
       for(int i=1;i<=n;i++)
        for(int j=w[i];j<=m;j++)
        dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        cout<<dp[m]<<endl;
   }
   //system("pause");
   return 0;
}
