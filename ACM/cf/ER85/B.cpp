#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn];
bool cmp(ll x,ll y){
    return x>y;
}
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,x;
       cin>>n>>x;
       ll sum=0;
       for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
       sort(a+1,a+n+1,cmp);
       ll ans=0;
       for(int i=n;i>=1;i--)
       {
           if(sum>=x*i)
           {
               ans=i;
               break;
           }
           sum-=a[i];
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
