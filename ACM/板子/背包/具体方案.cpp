#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e3+10;
int dp[maxn][maxn],v[maxn],w[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=n;i>=1;i--)
    	for(int j=m;j>=0;j--)
    	{
    		dp[i][j]=dp[i+1][j];
    		if(j>=v[i])
    		dp[i][j]=max(dp[i+1][j],dp[i+1][j-v[i]]+w[i]);
		}
    	
    for(int i=1;i<=n;i++)
    {
    	if(m>=v[i]&&dp[i][m]==dp[i+1][m-v[i]]+w[i])
    	{
    		cout<<i<<" ";
    		m-=v[i];
		}
	}
}

