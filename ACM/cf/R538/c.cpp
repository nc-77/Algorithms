#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const long long inf=10e12;
const int maxn=2e6+10;
ll fac(ll n,ll x)
{
    ll res=0;
    while(n/x!=0)
    {
        res+=n/x;
        n=n/x;
    }
    return res;
}
map<ll,ll>prime;
int main()
{
   ll n,b;
   cin>>n>>b;
   //ll m=sqrt(b);
    for(int i=2;i<=b/i;i++)
    { 
          while(b%i==0)
        {
            prime[i]++;
            b=b/i;
        }
    }
    if(b>1) prime[b]++;
    ll ans=0;
    int flag=1;
    for(auto x:prime)
    {
        ll t=x.first;
        ll s=x.second;
        if(flag) {ans=fac(n,t)/s;flag=0;continue;}
         ans=min(ans,fac(n,t)/s);
    }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
