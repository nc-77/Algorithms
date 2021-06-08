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
int dp[1000000+10],a[100];
int main()
{
	int n,num=0;
	cin>>n;
	dp[0]=1;
	int i,j;
	for( i=1;i<=n;i=i<<1)
	{
		a[num++]=i;

	}
	for( i=0;i<num;i++)
		for(j=a[i];j<=n;j++)
		{
			dp[j]=(dp[j]+dp[j-a[i]])%1000000000;
		}
	cout<<dp[n]<<endl;	
}
