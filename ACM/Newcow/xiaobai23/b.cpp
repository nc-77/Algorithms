#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<ll,ll>prime;
int vis[100];
int cnt;
void fac(ll n)
{   
    for(int i=2;i<=n/i;i++)
    {   if(n%i==0) vis[cnt++]=i;
          while(n%i==0)
        {
            prime[i]++;
            n=n/i;
        }
    }
    if(n>1) prime[n]++,vis[cnt++]=n;
}
bool judge(ll n)
{
    for(int i=0;i<cnt;i++) 
    {   ll x=vis[i];
        ll num=prime[x];
        ll ans=0;
        while(n/x>0)
        {
            ans+=n/x;
            x=x*x;
        }
        if(ans>=num) continue;
        else  return false;
    }
    return true;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {    set0(vis);
        cnt=0;
    prime.clear();
       ll p;
       cin>>p;
       fac(p);
       ll l=0,r=p;
       while(r-l>1)
       {
           ll mid=(l+r)/2;
           if(judge(mid))
           r=mid;
           else l=mid;
       }
        cout<<r<<endl;
   }
   //system("pause");
   return 0;
}
