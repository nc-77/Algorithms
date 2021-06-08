#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define mod 998244353
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll h[maxn],f[maxn];
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) 
   {
       if(i%2) h[i]=1;
       else
       {
           if((i/2)%2) h[i]=2;
           else h[i]=2*h[i/2]%mod;
       }
       
   }
   
   ll ans=0;
   for(int i=1;i<=n;i++) 
   {
       ans=ans+n/i*h[i];
       ans=ans%mod;
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}