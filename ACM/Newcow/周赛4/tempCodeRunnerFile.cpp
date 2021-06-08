#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int f(int a,int b)
{
   int ans=0;
   if(b<=a/4.0)
   ans=b;
   else if(b>=3.0*a/2)
   ans=a/2;
   else 
   {
      ans=max(a/4,max(b/3,(4*b-a)/10+(3*a-2*b)/10));
   }
   return ans;
}
signed main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      int a,b;
      cin>>a>>b;
      int ans=f(a,b);
      for(int i=0;i<=1000;i++)
      {
         int aa=a-i*4,bb=b-i;
         if(aa<0||bb<0) break;
         ans=max(ans,i+min(aa/2,bb/3));
      }
      cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
