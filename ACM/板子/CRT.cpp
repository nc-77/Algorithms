#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll p[maxn],a[maxn];
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
ll inv(ll a,ll p)
{   ll x=1,y=0;
    exgcd(a,p,x,y);
    x=(x%p+p)%p;
    return x;
}
ll crt(int n)
{
    ll ans=0,lcmp=1;
    for(int i=1;i<=n;i++) lcmp*=p[i];
    for(int i=1;i<=n;i++)
    {
        ll t=lcmp/p[i];
        ans=(ans+a[i]*t*inv(t,p[i]))%lcmp;
        debug(inv(t,p[i]));
        debug(ans);
    }
    ans=(ans%lcmp+lcmp)%lcmp;
    return ans;
}
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>p[i]>>a[i];
    cout<<crt(n)<<endl;
   return 0;
}
