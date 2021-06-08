#include<bits/stdc++.h>
#define ll long long
const int p=1e9+7;
using namespace std;
ll mypow(ll a,ll b)
{
	
	long long ans=1;
	for(;b;b=b>>1)
	{	if(b&1) ans=ans*a%p; 
			a=a*a%p;
	}
	return ans;
}
int main()
{
	ll n,m,st;
	cin>>n>>m;
	if(n>m) swap(n,m);
	 st=6*mypow(4,n-2)%p;
	ll ans=st*mypow(2,m-3)%p;
	cout<<ans<<endl;
}
