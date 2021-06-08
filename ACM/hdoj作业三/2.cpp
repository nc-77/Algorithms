#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e3+10;
struct node
{
	int l,r;
}s[maxn];
bool cmp(node x,node y)
{
	if(x.l<y.l) return true;
	if(x.l==y.l) return x.r<y.r;
	return false;
}
int vis[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {	set0(vis),set0(s);
    	int n;
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	{
    		int x,y;
    		cin>>x>>y;
    		if(x>y) swap(x,y);
    		if(x%2==0) s[i].l=x/2;
    		else s[i].l=(x+1)/2;
    		if(y%2==0) s[i].r=y/2;
    		else s[i].r=(y+1)/2;
    		
		}
		sort(s+1,s+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n;i++)
		{	if(vis[i]) continue;
			vis[i]=1;
			ans++;
			int last=i;
			for(int j=i+1;j<=n;j++)
			{
				if(vis[j]) continue;
				if(s[j].l>s[last].r)
				vis[j]=1,last=j;
			}
		}
		cout<<ans*10<<endl;
	}
}

