#include<std>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e5+10;
struct node
{
	ll v,t;
}s[maxn];
bool cmp(node x,node y)
{
	return x.v*1.0/x.t>y.v*1.0/y.t;
}
ll sv,st;
int main()
{
    
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++)
    	{
    		cin>>s[i].v>>s[i].t;
    		//sv+=s[i].v,st+=s[i].t;
		}
    	sort(s,s+n,cmp);
    	ll ans=0,t=0;
    	for(int i=0;i<n;i++)
    	{
    		t+=s[i].t;
    		ans+=s[i].v*t;
		}
		cout<<ans<<endl;
	
}

