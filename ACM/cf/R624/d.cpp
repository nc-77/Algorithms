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
    int T;
    cin>>T;
    while(T--)
    {
    	int a,b,c,bb,cc,x,y,z,tt;
    	int ans=inf; 
    	cin>>a>>b>>c;
    	for(int i=1;i<=20000;i++)
    		for(int j=i;j<=20000;j+=i)
    			for(int k=j;k<=20000;k+=j)
    			{
    				if(fabs(k-c)+fabs(j-b)+fabs(i-a)<ans)
    				{
    					ans=fabs(k-c)+fabs(j-b)+fabs(i-a);
    					z=i;
    					x=j;
    					y=k;
					}
				}

		cout<<ans<<endl;
		cout<<z<<" "<<x<<" "<<y<<endl;
	}
}

