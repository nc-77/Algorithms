#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll dp[maxn];
map<ll,int>mp;
int main()
{   int n;
   dp[1]=1;
   int a=1,b=1,c=1,d=1;
   mp[1]=1;
   for(int i=2;i<=5842;i++)
   {
       dp[i]=min(dp[a]*2,min(dp[b]*3,min(dp[c]*5,dp[d]*7)));
       if(dp[i]==dp[a]*2) a++;
       if(dp[i]==dp[b]*3) b++;
       if(dp[i]==dp[c]*5) c++;
       if(dp[i]==dp[d]*7) d++;
       mp[dp[i]]=1;
   }
   int t;
   cin>>t;
   while(t--)
   {
       ll x;
       cin>>x;
       if(mp[x]) puts("Yes");
       else puts("No");
   }
   //system("pause");
   return 0;
}
