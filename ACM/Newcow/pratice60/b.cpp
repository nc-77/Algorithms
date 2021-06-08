#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define mod 998244353
ll x[maxn],y[maxn];
int main()
{
   ll n;
   cin>>n;
   ll sum=0;
   for(int i=1;i<=n;i++) cin>>x[i]>>y[i],x[i],y[i];
   for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        sum=sum+(abs(x[i]-x[j])%mod+abs(y[i]-y[j])%mod)%mod;
        sum=sum%mod;
    }
    sum=sum*(n-2);
    sum=sum%mod;
    cout<<sum<<endl;
   //system("pause");
   return 0;
}
