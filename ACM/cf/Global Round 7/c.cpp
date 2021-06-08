#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define mod 998244353
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
struct node
{
    ll id,num;
}a[maxn];
bool cmp(node x,node y)
{
    return x.num>y.num;
}
ll vis[maxn];
int main()
{
   ll n,k;
   cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i].num,a[i].id=i;
    sort(a+1,a+n+1,cmp);
    ll ans=0,x=1;
    int cnt=0;
    for(int i=1;i<=k;i++)
    {
        ans+=a[i].num;
        vis[cnt++]=a[i].id;
    }
    sort(vis,vis+cnt);
    //debug(x);
    for(int i=1;i<cnt;i++) x=(x%mod)*(vis[i]-vis[i-1])%mod,x=x%mod;
    cout<<ans<<" "<<x%mod<<endl;
   //system("pause");
   return 0;
}
