#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll fun(ll x)
{	ll ans=0;
	ll t=sqrt(x);
	for(int i=1;i<=t;i++)
	{
		if(x%i==0)
		ans+=2;
	}
	if(x==t*t) ans--;
	return ans;
}
int main()
{	ll sum=0;
	ll n;
	cin>>n;
	while(1)
	{	sum++;
		n=fun(n);
		//cout<<n<<endl;
		if(n==2)
		{
			break;
		}
		
	}
	cout<<sum<<endl;
}
