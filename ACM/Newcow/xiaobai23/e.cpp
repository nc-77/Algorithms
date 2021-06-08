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
   ll ans=4294967296+2;
   ll x=ans-abs(n+1);
   cout<<max(x,0ll)<<endl;
   //system("pause");
   return 0;
}
