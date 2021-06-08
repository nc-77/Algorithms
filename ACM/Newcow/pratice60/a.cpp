#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn],bit[maxn];
int main()
{
   int n;
   cin>>n;
   ll sum=0,ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        ll x=a[i];
        int cnt=1;
        while(x)
        {
            if(x&1) bit[cnt]++;
            cnt++;
            x=x>>1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        ll x=a[i];
        int cnt=1;
        while(x)
        {
            if(x&1)  ans+=bit[cnt]*(1<<(cnt-1));
            cnt++;
            x=x>>1;
        }
    }
    cout<<ans<<endl;
   //system("pause");
   return 0;
}
