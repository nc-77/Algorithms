#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<ll,ll>mp;
int main()
{
   for(ll i=1;i<=100000;i++)
   {
       mp[i*i]=i;
   }
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       ll l,r;
       cin>>l>>r;
       ll st=l;
       ll x=sqrt(l),y=sqrt(r);
       l=x*x;
       r=y*y;
       //debug(l),debug(r);
       ll ans=mp[r]-mp[l];
       if(st==l) ans++;
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
