#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define q 998244353
const int maxn=200000+10;
ll a[maxn];
ll sum[maxn];
ll b[maxn];
ll qpow(ll a, int b) {
  ll ans = 1;
  a = (a % q + q) % q;
  for (; b; b >>= 1) {
    if (b & 1) ans = (a * ans) % q;
    a = (a * a) % q;
  }
  return ans;
}
int main()
{	ll maxx=0;
	ll n,k,i;
	cin>>n>>k;
	ll cnt=0;
	sum[0]=1;
	for( i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) 
		{
			a[i]=1;
			b[cnt++]=i;
		}
		sum[i]=sum[i-1]*a[i]%q;
	}
	
	for( i=1;i<=n-k+1;i++)
	{	ll x;
		int flag=0;
		ll pos=lower_bound(b,b+cnt,i)-b;
		if(pos>=cnt) flag=1;
		else 
		{
			if(b[pos]<=i+k-1)
			flag=0;
			else 
			flag=1;
		}
		if(flag) 
		 x=sum[i+k-1]*qpow(sum[i-1],q-2)%q;
		 else x=0;
		 maxx=max(maxx,x);
	}
	cout<<maxx%q<<endl;
}
