#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
signed main()
{
   //ios::sync_with_stdio(false);
   int a,b,c,d;
   cin>>a>>b>>c>>d;
   int ans=0;
    for(int i=a+b;i<=b+c;i++)
    {
        int cnt=min(i-a,c)-max(i-b,b)+1;
        if(cnt>=1) ans+=cnt*max(0ll,min(i-1,d)-c+1);
    }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
