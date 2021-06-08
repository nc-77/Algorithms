#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e3+10;
ll a[maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    ll ans1=0,ans2=0;
    for(int i=1;i<=n-1;i++)
    ans1+=a[n]-a[i];
    for(int i=2;i<=n;i++)
    ans2+=a[i]-a[1];
    cout<<max(ans1,ans2)<<endl;
}

