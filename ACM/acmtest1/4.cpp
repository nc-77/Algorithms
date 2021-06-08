#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll dp[maxn],ans[maxn];
map<ll,ll>mp[10];
int main()
{   int n;
   dp[1]=1;
   int a=1,b=1,c=1,d=1;
   mp[1]=1;
   for(int i=2;i<=5842;i++)
   {
       dp[i]=min(dp[a]*2,min(dp[b]*3,min(dp[c]*5,dp[d]*7)));
       if(dp[i]==dp[a]*2) a++,mp[dp[i]][2]=mp[dp[a]][2]+1;
       if(dp[i]==dp[b]*3) b++,mp[dp[i]][3]=mp[dp[b]][3]+1;
       if(dp[i]==dp[c]*5) c++,mp[dp[i]][5]=mp[dp[c]][5]+1;
       if(dp[i]==dp[d]*7) d++,mp[dp[i]][7]=mp[dp[d]][7]+1;
       
   }
   ll x;
   while(cin>>x&&x)
   {
       ll ans=(mp[x][2]+1)*(mp[x][3]+1)*(mp[x][5]+1)*(mp[x][7]+1);
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
