#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e3+10;
ll a[maxn],dp[maxn][maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    int cnt=1;
    while(t--)
    {	set0(dp),set0(a);
    	
    	int n;
    	cin>>n;
    	for(int i=1;i<=n;i++) cin>>a[i];
    	for(int len=3;len<=n;len++)
    		for(int i=1;i<=n-len+1;i++)
    		{
    			int j=i+len-1;
    			for(int k=i+1;k<j;k++)
    			{
    				dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+a[i]*a[j]*a[k]);
    				//debug(i),debug(j),debug(k),debug(dp[i][j]);
				}
			}
    	printf("Case #%d: %lld\n",cnt++,dp[1][n]);
	}
}

