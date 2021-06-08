#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn],x[maxn],b[maxn];
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>b[i];
   ll mx=b[1];
   a[1]=b[1];
   for(int i=2;i<=n;i++)
   {
       a[i]=b[i]+mx;
       mx=max(mx,a[i]);
   }
   cout<<a[1];
   for(int i=2;i<=n;i++) cout<<" "<<a[i];
   //system("pause");
   return 0;
}
