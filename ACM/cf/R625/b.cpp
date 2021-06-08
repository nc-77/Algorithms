#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
ll a[maxn],b[maxn];
map<ll,ll>mp;
signed main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
    	a[i]=b[i]-i;
    	mp[a[i]]+=b[i];
    	ans=max(ans,mp[a[i]]);
	}
	cout<<ans<<endl;
}

