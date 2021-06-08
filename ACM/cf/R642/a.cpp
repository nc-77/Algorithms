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
       int n,m;
       cin>>n>>m;
       if(n==1) {
           cout<<0<<endl;
           continue;
       }
       else if(n==2){
           cout<<m<<endl;
       }
       else {
           cout<<m*2<<endl;
       }
   }
   //system("pause");
   return 0;
}
