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
       ll a,b;
       cin>>a>>b;
       ll ans=a/b;
       ll y=b*(ans+1)-a;
       if(a%b==0) y=0;
       cout<<y<<endl;

   }
   //system("pause");
   return 0;
}
