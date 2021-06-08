#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll jc(int n)
{	ll ans=1;
	for(int i=1;i<=n;i++)
	ans=ans*i;
	return ans;
}
int main()
{
	ll s=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		//cout<<jc(i)<<endl;
		s+=jc(i);
	}
	cout<<s<<endl;
}
