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
       ll n;
       cin>>n;
       ll ans=n/2;
       if(n%2==0) ans--;
       cout<<ans<<endl; 
   }
   //system("pause");
   return 0;
}
