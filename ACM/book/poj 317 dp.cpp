#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int dp[400][400];
int main()
{	int maxx=0;
	int n,a[400][400];
	cin>>n;
	for(int i=1;i<=n;i++)
	{	
		for(int j=1;j<=i;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==1&&j==1) dp[i][j]=a[i][j];
			else if(j==1) dp[i][j]=dp[i-1][j]+a[i][j];
			else if(j==i) dp[i][j]=dp[i-1][j-1]+a[i][j];
			dp[i][j]=max(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]);
			maxx=max(dp[i][j],maxx);
		}
	}
	cout<<maxx<<endl;
}
