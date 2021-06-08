#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1e3+10;
ll b[maxn][maxn],a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    ll ans=0,maxx=0,maxi;
    for(int i=1;i<=n;i++)
    {	ans=a[i];
    	b[i][i]=a[i];
    	for(int j=i-1;j>=1;j--)
    	{
    		b[i][j]=min(a[j],b[i][j+1]);
    		ans+=b[i][j];
		}
    	for(int j=i+1;j<=n;j++)
    	{
    		b[i][j]=min(a[j],b[i][j-1]);
    		ans+=b[i][j];
		}
		if(ans>maxx)
		{
			maxi=i;
			maxx=ans;
		}
	}
	//cout<<maxx<<endl;
	cout<<b[maxi][1];
	for(int i=2;i<=n;i++)
	cout<<" "<<b[maxi][i];
}

