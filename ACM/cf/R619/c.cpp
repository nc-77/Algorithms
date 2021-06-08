#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll n0=n-m;
		ll ans=n*(n+1)/2;
		ll k=n0/(m+1);
		ll g=n0%(m+1);
		ans-=k*(k+1)/2*(m+1)+g*(k+1);
		cout<<ans<<endl;
	}
}

