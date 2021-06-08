#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int p[50000+10],w[10000+10],dp[11000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int e,f,n;
		cin>>e>>f>>n;
		int maxv=f-e;
		for(int i=0;i<n;i++)
		cin>>p[i]>>w[i];
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=w[i];j<=maxv;j++)
			{
				dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
				//printf("%d  %d %lld\n",i,j,dp[j]);
			}
			
		}
		//cout<<inf<<endl;
		if(dp[maxv]==inf) cout<<"This is impossible."<<endl;
		else printf("The minimum amount of money in the piggy-bank is %lld.\n",dp[maxv]);		 
	}
}
