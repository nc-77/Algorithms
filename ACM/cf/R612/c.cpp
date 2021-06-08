#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int a[105];
int dp[105][105][105][3]; 
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(dp,inf,sizeof(dp));
	int x=n/2,y=n-x;
	dp[0][0][0][0]=dp[0][0][0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=x;j++)
		{
			for(int k=0;k<=y;k++)
			{
				if(a[i]==0||a[i]&&a[i]%2)
				dp[i][j][k+1][1]=min(dp[i-1][j][k][0]+1,dp[i-1][j][k][1]);
				if(a[i]==0||a[i]&&a[i]%2==0)
				dp[i][j+1][k][0]=min(dp[i-1][j][k][1]+1,dp[i-1][j][k][0]);
			}
		}
		int ans=inf;
	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<=y;j++)
		ans=min(ans,min(dp[n][i][j][0],dp[n][i][j][1]));
	}
	cout<<ans<<endl;
}

