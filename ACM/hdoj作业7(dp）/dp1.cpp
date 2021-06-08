#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,maxv,w[1010],v[1010],dp[1010];
		cin>>n>>maxv;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>w[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=maxv;j>=w[i];j--)
			{
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		cout<<dp[maxv]<<endl;
	}
 } 
