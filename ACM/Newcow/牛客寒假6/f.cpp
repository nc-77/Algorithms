#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
const int q=1e9+7;
ll a[2050],b[2050],sum[2050][2050];
int main()
{	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	while(k--)
	{
		ll x,y,z;
		cin>>x>>y>>z;
		a[x]+=z%q;
		b[y]+=z%q;
		sum[x][y]+=z%q;
	}
	ll ans=0,i,j;
	for( i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			ans+=(a[i]+b[j]-sum[i][j])%q*(i+j)%q; 
			//debug(a[i]+b[j]);
		}
	cout<<ans%q<<endl;	
}

