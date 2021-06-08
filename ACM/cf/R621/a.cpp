#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int a[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
    	int n,d;
    	cin>>n>>d;
    	for(int i=0;i<n;i++)
    	{
    		
    		cin>>a[i];
    		
		}
		int ans=a[0];
		for(int i=1;i<n;i++)
		{
			if(d<i) break;
			ans+=min(a[i],d/i);
			d-=min(a[i],d/i)*i;
		}
		cout<<ans<<endl;
	}
}

