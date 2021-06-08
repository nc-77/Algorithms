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
    {	int ans=0;
    	int a[3];
    	cin>>a[0]>>a[1]>>a[2];
    	if(a[0])  
    	{
    		ans++;
    		a[0]--;
		}
		if(a[1])  
    	{
    		ans++;
    		a[1]--;
		}
		if(a[2])  
    	{
    		ans++;
    		a[2]--;
		}
		//debug(ans);
		sort(a,a+3);
		if(a[2]>=2)
		{
			if(a[0])
			{
				a[0]--;
				ans++;
			}
			if(a[1])
			{
				a[1]--;
				ans++;
			}
			if(a[1]&&a[0]) 
			{
				ans++;
				a[1]--;
				a[0]--;
			}
			if(a[1]&&a[0]&&a[2])
			{
				ans++;
				a[1]--;
				a[0]--;
			}
		}
		else
		{
			if(a[2]==1&&a[1]==1)
			ans++;
			
			
		}
		cout<<ans<<endl;
	}
}

