#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
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
		cin>>x>>y>>a>>b;
		if((y-x)%(a+b)!=0) puts("-1");
		else cout<<(y-x)/(a+b)<<endl;
	} 
}

