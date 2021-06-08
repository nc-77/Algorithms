#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size(),dp[100][100]={0},maxx=0;
	for(int i=1;i<=len1;i++)
	{
		for(int j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
				maxx=max(maxx,dp[i][j]); 
			}
			else dp[i][j]=0;
		}
	}
	cout<<maxx<<endl;
 } 
