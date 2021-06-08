#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   ll n;
   cin>>n;
   ll t=n;
   ll rev=0;
   while(t)
   {
       rev=rev*10+t%10;
       t=t/10;
   }
    ll ans=rev+n;
    cout<<ans<<endl;
   //system("pause");
   return 0;
}
