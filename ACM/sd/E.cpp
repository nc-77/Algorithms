#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn];
int main()
{
   ll n;
   cin>>n;
   ll sum=0;
   for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
   ll ans=sum-n*(n-1)/2;
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
