#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int n;
   ll ans=0;
   cin>>n;
   for(int i=0;i<n;i++) 
   {
       ll x;
       cin>>x;
       if(x<0) ans++;
   }
   cout<<ans*(n-1)<<endl;
   //system("pause");
   return 0;
}
