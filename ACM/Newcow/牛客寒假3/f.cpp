#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int  p=1000000000+7;
ll a[100000+10];
int main()
{
	int n,last=0;
	ll cnt=0;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1') 
		{
			a[cnt++]=i-last;
			last=i;
		}
	}
	ll ans=0,sum=0;
	for(ll i=1;i<cnt;i++)
	{
		
		ans+=(i*(cnt-i)%p)*a[i]%p;
		
	}
	cout<<ans%p<<endl;
}
