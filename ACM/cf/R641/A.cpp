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
       int n,k;
       cin>>n>>k;
       if(n%2==0) {
           cout<<n+2*k<<endl;
       }
       else {
           k--;
           for(int i=3;i<=n;i++)
            {
                if(n%i==0) {
                    n+=i;
                    break;}
            }
            cout<<n+2*k<<endl;
       }
   }
   //system("pause");
   return 0;
}
