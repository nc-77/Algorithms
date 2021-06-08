#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn];
map<ll,ll>mp;
ll n;
signed main()
{
   
   cin>>n;
   ll ans=0,sum=0;
    for(int i=1;i<=n;i++) 
    {cin>>a[i];
    }
    ll maxl=0;
    for(int i=1;i<=n;i++)
    {
       sum+=a[i];
       if(mp[sum]||sum==0) maxl=max(maxl,mp[sum]+1);
        mp[sum]=i;
        ans+=i-maxl;
    }
    cout<<ans<<endl;
   //system("pause");
   return 0;
}
