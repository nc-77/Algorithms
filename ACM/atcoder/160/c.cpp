#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn];
int main()
{
   ll k,n;
   cin>>k>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   ll mx=k-a[n]+a[1];
   for(int i=1;i<n;i++)
   {
       mx=max(mx,a[i+1]-a[i]);
   }
   cout<<k-mx<<endl;
   //system("pause");
   return 0;
}
