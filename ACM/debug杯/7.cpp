#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
int a[maxn],b[maxn];
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       for(int i=1;i<=n;i++) cin>>a[i];

       if(n>m) puts("0");
       else
       {
           int ans=1;
           for(int i=1;i<=n;i++)
           {
               for(int j=i+1;j<=n;j++)
               {
                   ans=(ans%m)*(abs(a[i]-a[j])%m);
                   ans=ans%m;
               }
           }
           cout<<ans<<endl;
       }
       
   }
   //system("pause");
   return 0;
}
