#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll p[10],a[10];
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
ll rct(int n)
{
    ll ans=0,lcmp=1;
    for(int i=1;i<=n;i++) lcmp*=p[i];
    for(int i=1;i<=n;i++)
    {
        ll t=lcmp/p[i];
        ans=(ans+a[i]*t*inv(t,p[i]))%lcmp;
    }
    ans=(ans%lcmp+lcmp)%lcmp;
    return ans;
}
int main()
{   int T;
    cin>>T;
    while(T--)
    {
        int ca=1;
    p[1]=23,p[2]=28,p[3]=33;
    ll t;
   while(cin>>a[1]>>a[2]>>a[3]>>t)
   {
       if(t==-1) break;
       ll ans=rct(3);
        ans-=t;
        if(ans<=0)ans+=21252;
    printf("Case %d: the next triple peak occurs in %lld days.\n",ca++,ans);
   }
   
    }
    
   //system("pause");
   return 0;
}
