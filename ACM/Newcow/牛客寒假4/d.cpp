#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll sum[200000+10];
ll a[200000+10];
map<ll,ll>mp;
int main()
{
	int n;
	ll ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(sum[i]==0) ans++;
		mp[sum[i-1]]++;
		ans+=mp[sum[i]];
	}
	if(a[1]==0) ans++;
	cout<<ans<<endl;
}
