#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int main()
{	ll cnt=0;
    //freopen("in.txt","r",stdin);
    for(int i=-2147483648;i<=2147483647;i++)
    	{
    	    ll t=0-i;
    		if(t>=-2147483648&&t<=2147483647) cnt++;
		}
		cout<<cnt<<endl;
}
