#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       if(k>=n){
           cout<<1<<endl;
       }
       else {
           int x=sqrt(n);
           int ans=inf;
           for(int i=1;i<=x;i++)
           {
               if(n%i==0){
                   if(i<=k)ans=min(ans,n/i);
                   if(n/i<=k) ans=min(ans,i);
               }
           }
           cout<<ans<<endl;
       }
   }
   //system("pause");
   return 0;
}
