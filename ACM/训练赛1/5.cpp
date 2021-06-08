#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
const int mod=1e9+7;
ll a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    ll cnt=0;
    ll ans=1;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{	ans=ans*(a[i]-i+1)%mod;
	}
	cout<<ans%mod<<endl;
}

