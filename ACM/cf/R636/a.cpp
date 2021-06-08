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
       ll x;
       cin>>x;
       ll ans=1,k=1,now=2;
       while(1)
       {
           if(x%k==0&&k>1)
           {
               ans=x/k;
               break;
           }
           k+=now;
           now=now*2;
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
