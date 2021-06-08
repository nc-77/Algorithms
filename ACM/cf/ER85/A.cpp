#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int x,y,px,py;
       int flag=1;
       cin>>px>>py;
       if(py>px) flag=0;
       for(int i=2;i<=n;i++)
       {
          cin>>x>>y;
          //debug(x),debug(y),debug(px),debug(py);
         if(y>py&&x<=px) flag=0;
         else if(y<py||x<px) flag=0;
         else if(y>x) flag=0;
         else if(x-px<y-py) flag=0;
         px=x,py=y;
       }
      if(flag) puts("YES");
      else puts("NO");
   }
   //system("pause");
   return 0;
}
