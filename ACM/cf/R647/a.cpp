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
   int t;
   cin>>t;
   while(t--)
   {
       ll a,b;
       cin>>a>>b;
       if(a>b) swap(a,b);
       if(b%a!=0) {
           cout<<-1<<endl;
           continue;
       }
       ll x=b/a;
       ll ans=0;
       while(x!=1)
       {
           if(x%8==0) x=x/8,ans++;
           else break;
       }
        while(x!=1)
       {
           if(x%4==0) x=x/4,ans++;
           else break;
       }
       while(x!=1)
       {
           if(x%2==0) x=x/2,ans++;
           else break;
       }
       if(x==1) cout<<ans<<endl;
       else cout<<-1<<endl;
   }
   //system("pause");
   return 0;
}
