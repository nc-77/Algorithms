#include<bits/stdc++.h>
#define ll long long
const int  p=1000000000+7;
using namespace std;
int n,m;
char a[55][55];
ll dp[55][55];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if((a[i-1][1]=='B'||a[i-1][1]=='D')&&dp[i-1][1]) 
		dp[i][1]=1;
		else dp[i][1]=0;
		//cout<<i<<" "<<dp[i][1]<<endl;
	}
	for(int i=2;i<=m;i++)
	{
		if((a[1][i-1]=='B'||a[1][i-1]=='R')&&dp[1][i-1])
		dp[1][i]=1;
		else dp[1][i]=0;
		//cout<<i<<" "<<dp[1][i]<<endl;
	}
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
		{	
			if(a[i-1][j]=='B'||a[i-1][j]=='D')
			dp[i][j]+=dp[i-1][j]%p;
			if(a[i][j-1]=='B'||a[i][j-1]=='R')
			dp[i][j]+=dp[i][j-1]%p;
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	cout<<dp[n][m]%p<<endl;
} 
