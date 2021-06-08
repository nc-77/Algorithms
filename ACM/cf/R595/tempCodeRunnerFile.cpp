#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn],sa[maxn],sb[maxn];
signed main()
{
   int n,c;
   cin>>n>>c;

   for(int i=1;i<=n;i++) cin>>a[i],sa[i]=sa[i-1]+a[i];
   for(int i=1;i<=n;i++) cin>>b[i],sb[i]=sb[i-1]+b[i];
   for(int i=1;i<=n;i++)
   {
       cout<<min(sa[i],sb[i]+c)<<" ";
   }
   
   //system("pause");
   return 0;
}
