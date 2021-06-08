#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
ll a[150],b[150],vis[150];
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
    	ll n,m;
    	cin>>n>>m;
    	set0(a),set0(b),set0(vis);
    	for(int i=1;i<=n;i++)
    	{
    		ll x,y,z;
    		cin>>x>>y>>z;
    		vis[i]=x;
    		a[i]=y,b[i]=z;
    		
		}
		int flag=1;
		ll nn=m,ss=m;
		for(int i=1;i<=n;i++)
		{
			nn+=vis[i]-vis[i-1];
			ss-=vis[i]-vis[i-1];
			if(nn<a[i]||ss>b[i]) 
			{
				flag=0;
				break;
			}
			nn=min(b[i],nn);
			ss=max(a[i],ss);
		}
		if(flag) puts("YES");
		else puts("NO");
	}
}

