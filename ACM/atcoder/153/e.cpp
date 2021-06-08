#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int dp[10000000],cost[2000],weight[2000];
int main()
{
	int h,n;
	cin>>h>>n;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	int MIN=INF,mx=0;
	for(int i=0;i<n;i++)
	{
		cin>>cost[i]>>weight[i];
		mx=max(mx,weight[i]);
	}
	for(int i=0;i<n;i++)
		for(int v=cost[i];v<=max(h+h+h+h,mx);v++)
	{
		dp[v]=min(dp[v],dp[v-cost[i]]+weight[i]);
		if(v>=h) 
		{
			MIN=min(dp[v],MIN);
		}
	}
	cout<<MIN<<endl;
}
