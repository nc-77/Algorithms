#include<bits/stdc++.h>
using namespace std;
int p[110],h[110],c[110],dp[110][110];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	memset(dp,0,sizeof(dp));
		int n,m,i,j,MAX=0;
		cin>>n>>m;
		for( i=0;i<m;i++)
		{
			scanf("%d%d%d",&p[i],&h[i],&c[i]);
		}
		for( i=0;i<m;i++)
		{
			for( j=p[i];j<=n;j++)
			{	MAX=0;
				for(int k=0;k<=min(j/p[i],c[i]);k++) 
				{
					dp[i+1][j]=dp[i][j-k*p[i]]+k*h[i];
					
					if(dp[i+1][j]>=MAX)
					MAX=dp[i+1][j];
					//printf("dp %d  max %d\n",dp[i+1][j],MAX);
				}
				dp[i+1][j]=MAX;
				//printf("%d  %d %d\n",i,j,dp[i+1][j]);
			}
		}
		cout<<dp[m][n]<<endl;
	}
}
