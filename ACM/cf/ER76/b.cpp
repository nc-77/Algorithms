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
       ll x,y;
       cin>>x>>y;
       int flag=0;
       if(x==1)
       {
           if(y==x) puts("YES");
           else puts("NO");
       }
       else if(x==2||x==3)
       {
            if(y==1||y==2||y==3) puts("YES");
           else puts("NO");
       }
       else puts("YES");
   }
   //system("pause");
   return 0;
}
