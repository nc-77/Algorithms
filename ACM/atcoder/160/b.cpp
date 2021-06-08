#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   ll x;
   cin>>x;
   ll a=x/500;
   ll b=(x-a*500)/5;
   ll ans=a*1000+b*5;
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
