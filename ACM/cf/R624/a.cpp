#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1e3+10;
int a[maxn],vis[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    while(T--)
    {	int flag=1;
    	int n,m;
    	set0(vis),set0(a);
    	cin>>n>>m;
    	for(int i=1;i<=n;i++) cin>>a[i];
    	while(m--)
    	{
    		int x;
    		cin>>x;
    		vis[x]=1;
    		if(a[x]>a[x+1]) swap(a[x],a[x+1]);
		}
		for(int i=1;i<=n-1;i++)
		{	for(int j=1;j<=n-1;j++)
			if(a[j]>a[j+1])
			{	if(vis[j])
				swap(a[j],a[j+1]);
				else
				{
					flag=0;
				break;
				}
				
			}
		}
		for(int i=1;i<=n-1;i++)
		if(a[i]>a[i+1]) flag=0;
 		if(flag) puts("YES");
		else puts("NO");
	}
}

