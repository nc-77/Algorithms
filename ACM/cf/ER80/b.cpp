#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ws(ll b)
{	ll ans=0;
	while(b>0)
	{
		b=b/10;
		ans++;
	}
return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,ans=0;
		cin>>a>>b;
		ans=ws(b+1)-1;
		
		cout<<ans*a<<endl;
	}
}
