#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
signed main()
{
   //ios::sync_with_stdio(false);
   ll n,k;
   cin>>n>>k;
   ll mod=pow(10,k+1);
   ll x=pow(10,k);
   ll ans=1,m=0;
   for(int i=1;i<=n;i++)
   {
       ans=ans*i%mod;
       while(ans%10==0) ans/=10;
       
   }
   for(int i=5;i<=n;i=i*5)
   {
       m+=n/i;
   }
   ans=ans%x;
   printf("%*0lld %lld",k,ans,m);
   //system("pause");
   return 0;
}
