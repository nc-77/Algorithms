#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
double c[maxn],d[maxn];
int main()
{
   int n;
   double v,u;
   cin>>n>>v>>u;
   for(int i=1;i<=n;i++) cin>>c[i];
   for(int i=1;i<=n;i++) cin>>d[i];
   double ans=0;
   for(int i=1;i<=n;i++)
      for(int j=0;j<n;j++)
         ans+=1.0/(c[i]-v-j*d[i]);
      ans=ans*u;
      printf("%.3f",ans);
   return 0;
}
