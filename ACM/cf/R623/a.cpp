#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
    	ll a,b,x,y;
    	cin>>a>>b>>x>>y;
    	x++;y++;
    	ll ans=max(max(b-y,y-1)*a,max(x-1,a-x)*b);
    	cout<<ans<<endl;
	}
}

