#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],s[maxn];
int main()
{
   int n;
   cin>>n;
   int ave=0,sum=0;
   for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
   ave=sum/n;
   for(int i=1;i<=n;i++) 
   {
       a[i]-=ave;
       if(i>=2)s[i]=s[i-1]+a[i];
   }
   sort(s+1,s+n+1);
   int x=-s[n/2+1];
   int ans=0;
   for(int i=1;i<=n;i++)
   {
       ans+=abs(x+s[i]);
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
