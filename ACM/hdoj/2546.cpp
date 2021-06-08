#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int dp[maxn],v[maxn];
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{	int n;
    //freopen("in.txt","r",stdin);
    while(cin>>n&&n)
    {
    	set0(dp);
    	
    	for(int i=1;i<=n;i++) 
		cin>>v[i];
    	sort(v+1,v+n+1,cmp);
    	int m;
    	cin>>m;
    	int t=m;
    	if(m<5)
    	{
    		cout<<m<<endl;
    		continue;
		}
		m=m-5;
		
    	for(int i=2;i<=n;i++)
    		for(int j=m;j>=v[i];j--)
    		dp[j]=max(dp[j],dp[j-v[i]]+v[i]);
    	cout<<t-dp[m]-v[1]<<endl;
	}
}

