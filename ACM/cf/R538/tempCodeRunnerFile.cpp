#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll fac(ll n,ll x)
{
    ll res=0;
    while(n/x!=0)
    {
        res+=n/x;
        x=x*x;
    }
    return res;
}
int main()
{
   ll n,b;
   cin>>n>>b;
   ll m=sqrt(b);
   ll ans=0;
   for(ll i=1;i<=m;i++)
   {
       if(b%i==0)
       {
           ll x=b/i;
           if(x*x==b)
           {
            ans+=fac(n,x)/2;
           }
           else ans+=fac(n,x);
       }
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
