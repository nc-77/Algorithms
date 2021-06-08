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
       ll a,b,n,s;
       cin>>a>>b>>n>>s;
       //int flag=0;
      ll x=s/n*n;
       s-=min(x,n*a);
      //debug(x),debug(s);
        if(s<=b) puts("YES");
        else puts("NO");
   }
   //system("pause");
   return 0;
}
