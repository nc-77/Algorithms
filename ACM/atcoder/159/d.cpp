#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
ll a[maxn],cnt[maxn];
ll f[maxn];
int main()
{
   int n;
   cin>>n;
   ll mx=0,sum=0;
   for(int i=1;i<=n;i++) cin>>a[i],cnt[a[i]]++,mx=max(mx,a[i]);
   for(int i=1;i<=mx;i++) sum+=(cnt[i]*(cnt[i]-1))/2,f[i]=(cnt[i]*(cnt[i]-1))/2;
    for(int i=1;i<=n;i++)
    {
        ll x=cnt[a[i]]-1;
        ll ans=x*(x-1)/2;
        ans=sum+ans-f[a[i]];
        cout<<ans<<endl;
    }
   //system("pause");
   return 0;
}
