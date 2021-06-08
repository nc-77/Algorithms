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
   //ios::sync_with_stdio(false);
   double l,h,H,L;
   cin>>h>>l>>H>>L;
   double x=H*l/L;
   double y=h*L/H;
   if(h<=x){
       double ans=h*y/2;
       printf("%.8f",ans);
   } 
   else
   {
      double ans=(h+h-x)*l/2;
       printf("%.8f",ans);
   }
   //system("pause");
   return 0;
}
