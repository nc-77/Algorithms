#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[150];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int maxx=0;
       for(int i=1;i<=n;i++) cin>>a[i],maxx=max(maxx,a[i]);
       int flag=1;
        for(int i=1;i<=n;i++) if((maxx-a[i])%2==1) 
        {
            flag=0;
            break;
        }
        if(flag) puts("YES");
        else puts("NO");
   }
   //system("pause");
   return 0;
}
