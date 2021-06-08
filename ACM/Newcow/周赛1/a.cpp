#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
int a[maxn],s[maxn];
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       int st=0;
       for(int i=1;i<=n;i++) cin>>a[i],s[i]=0;
       for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i],st+=i*a[i];
       int ans=0;
       for(int i=k+1;i<=n;i++)
       {
           int sum=s[i-1]-s[i-1-k];
           
           ans=max(ans,st+sum-k*a[i]);
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
