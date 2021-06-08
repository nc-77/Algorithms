#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
signed main()
{
   //ios::sync_with_stdio(false);
   int n,p;
   cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int x=abs(a[i]-p);
        int y=a[i]+p;
        int l=upper_bound(a+1,a+n+1,x)-a;
        if(l>n) continue;
        int r=lower_bound(a+1,a+n+1,y)-a;
        if(r==1) continue;
        r--;
        if(a[i]>x&&a[i]<y) ans--;
        ans+=r-l+1;
    }
    cout<<ans/2<<endl;
   //system("pause");
   return 0;
}
