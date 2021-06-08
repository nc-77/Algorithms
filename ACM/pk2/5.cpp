#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
#define int long long
int x[maxn],y[maxn],a[maxn],ans[maxn],sum[maxn];
signed main()
{
   int n,k;
   cin>>n>>k;
   for(int i=1;i<=n;i++)
    cin>>x[i]>>y[i];
    for(int i=0;i<=k;i++) ans[i]=999999999999;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int x0=x[i],y0=y[j];
            set0(a),set0(sum);
            for(int ii=1;ii<=n;ii++) 
            {
                a[ii]=abs(x0-x[ii])+abs(y0-y[ii]);
            }
            sort(a+1,a+n+1);
            for(int ii=1;ii<=k;ii++) sum[ii]=sum[ii-1]+a[ii];
            for(int kk=1;kk<=k;kk++)
            {
                ans[kk]=min(ans[kk],sum[kk]);
            }
        }
        for(int i=1;i<=k;i++)
        cout<<ans[i]<<endl;
   //system("pause");
   return 0;
}
