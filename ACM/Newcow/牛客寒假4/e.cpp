#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[500000+10];
int ans[500000+10];
bool cmp(ll a,ll b)
{
	return a>b;
}
int main()
{
	string s;
	cin>>s;
	ll len=0,cnt=0;

	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='+')
		len++;
		else a[cnt++]=s[i]-'0';
	}
	sort(a,a+cnt,cmp);
	ll n=cnt/(len+1);
	ll m=cnt%(len+1);
	ll c=0;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<len+1;j++)
		{	if(c+j>=cnt) break;
			ans[i]+=a[c+j];
		}
		if(ans[i]>=10) 
		{
			ans[i+1]+=ans[i]/10;
			ans[i]%=10;
		}
		c+=len+1;
	}
	//cout<<ans[0]<<" "<<ans[1]<<endl;
	if(ans[n+1]) cout<<ans[n+1];
	if(ans[n]) cout<<ans[n];
	else if(ans[n+1]) cout<<ans[n]; 
	for(int i=n-1;i>=0;i--)
	{		
		cout<<ans[i];
	}
	cout<<endl;
}
