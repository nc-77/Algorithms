#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       ll x,k;
       cin>>x>>k;
       ll ans=x/k;
       ll a=x%k;
       ll mx=min(k/2,a);
       cout<<ans*k+mx<<endl;
   }
   //system("pause");
   return 0;
}
