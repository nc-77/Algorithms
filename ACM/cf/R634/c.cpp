#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<ll,ll>mp;
ll a[maxn];
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       set<int>s;
        mp.clear();
        ll mx=0;
       for(int i=1;i<=n;i++)
       {
           cin>>a[i];
           mp[a[i]]++;
           mx=max(mp[a[i]],mx);
           s.insert(a[i]);
       }
       ll ans=0,x;
       for(int i=1;i<=n;i++)
       {
           ll t=s.size();
            if(t-1>=mp[i]) x=mp[i];
            else x=min(t,mp[i]-1);
           x=min(x,n/2);
           ans=max(ans,x);
       }
       cout<<min(ans,n/2)<<endl;
       
   }
   //system("pause");
   return 0;
}
