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
       int n,m,x,y;
       cin>>n>>m>>x>>y;
       if(x<=y)
       {
           if(n>=x) {
               cout<<m<<endl;
               continue;
           }
           else {
               int k=(x-n)/y;
               if(n+k*y<x) k++;
               cout<<m-k<<endl;
               continue;
           }
       }
       else {
           int k=(n+m*y)/x;
           if(n+(m-k)*y-(k-1)*(x-y)<x) k--;
           cout<<min(m,k)<<endl;
       }
   }
   //system("pause");
   return 0;
}
