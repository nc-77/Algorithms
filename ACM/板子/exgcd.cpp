#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
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
//ax+by=c,ax%b=c%b;
ll lieu(ll a,ll b,ll c,ll &x,ll &y)
{
    ll d=exgcd(a,b,x,y);
    if(c%d!=0)return 0;
    ll k=c/d;
    x*=k;
    y*=k;
    ll t=b/d;
    x=(x%t+t)%t;
    y=(c-a*x)/b;
    return x;
}
int main()
{   ll x=1,y=0;
   ll a,b;
   cin>>a>>b;
   cout<<lieu(a,b,1ll,x,y);
   return 0;
}
