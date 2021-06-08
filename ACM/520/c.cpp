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
   int n;
   cin>>n;
   int sx=0,sy=0,xx=0,yy=0;
   for(int i=1;i<=n;i++)
   {
       int sex,x;
        cin>>sex>>x;
        if(sex==1) sx+=x,xx++;
        else sy+=x,yy++;
   }
   printf("%.1f ",(sx+sy)*1.0/n);
   if(xx) printf("%.1f ",(sx)*1.0/xx);
   else cout<<"X ";
   if(yy) printf("%.1f",(sy)*1.0/yy);
   else cout<<"X";
   //system("pause");
   return 0;
}
