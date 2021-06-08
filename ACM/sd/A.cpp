#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[5];
int main()
{
   for(int i=1;i<=4;i++) cin>>a[i];
   sort(a+1,a+5);
   ll ans=abs(a[1]+a[4]-a[2]-a[3]);
   ans=min(ans,abs(a[1]+a[3]-a[2]-a[4]));
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
