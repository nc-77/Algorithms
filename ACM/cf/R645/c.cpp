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
   int t;
   cin>>t;
   while(t--)
   {
       int x,y,xx,yy;
       cin>>x>>y>>xx>>yy;
       int d=abs(x-xx);
       int r=abs(y-yy);
       if(d==0||r==0)
       {
           cout<<1<<endl;
           continue;
       }
       int ans=(r+2*d-1)*r/2;
       ans=abs(ans-r*(r-1)/2);
       cout<<ans+1<<endl;

   }
   //system("pause");
   return 0;
}
