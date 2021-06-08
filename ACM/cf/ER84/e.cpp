#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define mod 998244353
ll quickpow(ll x,ll n)
{
	ll res=1;
	while(n)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main()
{
   ll n;
   cin>>n;
   for(ll i=1;i<=n;i++)
   {
       if(i==n) cout<<10<<" ";
       else if(i==n-1) cout<<180<<" ";// 不存在中间的情况
        else 
        {
            ll x=18*quickpow(10,n-i)%mod;//i块在首尾
            ll y=((n-i-1)%mod*81)%mod*quickpow(10,n-i-1)%mod;//i块在中间
            ll ans=(x+y)%mod;
            cout<<ans<<" ";
        }
   }
   //system("pause");
   return 0;
}
