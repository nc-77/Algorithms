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
    	ll a,b;
    	cin>>a>>b;
    	if(a==b) 
    	{
    		puts("0");
    		continue;
		}
		if(a<b)
		{
			if((b-a)%2==1)
			puts("1");
			else puts("2");
    		
		}
		else
		{
			if((a-b)%2==0)
			puts("1");
			else puts("2");
		}
	}
}

