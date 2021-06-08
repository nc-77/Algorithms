#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn],ans[maxn],sum[maxn];
int main()
{
   int n,m;
   cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {   sum[i]=sum[i-1]+a[i];
        if(i<=m)ans[i]=ans[i-1]+a[i];
        else
        {
            ans[i]=sum[i]+ans[i-m];
        }
        

    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
   //system("pause");
   return 0;
}
