#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[300000+10];
int main()
{
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	string s;
	cin>>s;
	//cout<<s<<endl;
	for(int i=3;i<n;i++)
	{	dp[i]=dp[i-1];
		if(i>=3&&s.substr(i-3,4)=="nico")
		dp[i]=max(dp[i],dp[i-3]+a);
		if(i>=5&&s.substr(i-5,6)=="niconi")
		dp[i]=max(dp[i],dp[i-5]+b);
		if(i>=9&&s.substr(i-9,10)=="niconiconi")
		dp[i]=max(dp[i],dp[i-9]+c);
	}
	cout<<dp[n-1]<<endl;
}
