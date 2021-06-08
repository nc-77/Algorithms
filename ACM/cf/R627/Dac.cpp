#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn],b[maxn];
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],a[i]-=b[i];
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n-1;i++)
    {
        int pos=upper_bound(a+i+1,a+n+1,-a[i])-a;
        ans+=n-pos+1;
    }
    cout<<ans<<endl;
  // system("pause");
   return 0;
}
