#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
ll a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
	if(n>m) puts("0");
	else
	{	ll ans=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ll x=(ll)fabs(a[i]-a[j])%m;
				ans=ans*x%m;
			}
		}
		cout<<ans%m<<endl;
	}
}

