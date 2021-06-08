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
       int n,x,a,b;
       cin>>n>>x>>a>>b;
       int ans=abs(a-b);
       cout<<min(ans+x,n-1)<<endl;
   }
   //system("pause");
   return 0;
}
