#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int flag=1;
       ll n,a,b,c,d;
       cin>>n>>a>>b>>c>>d;
       if(n*(a-b)>c+d||n*(a+b)<c-d) flag=0;
       if(flag)  puts("Yes");
       else puts("No");
   }
   //system("pause");
   return 0;
}
