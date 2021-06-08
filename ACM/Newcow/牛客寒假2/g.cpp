#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int ss[]={2,3,7,9,11,37,73,1000000007};
ll mypow(ll a,ll b,ll p)
{
	
		ll ans=1;
		for(;b;b=b>>1)
		{	if(b&1) ans=ans*a%p; 
			a=a*a%p;
		}
		//cout<<ans<<endl;
return ans%p;
}
ll ff(ll a, ll m) {
  return (a % m + m) % m;
}
int main()
{	
	int t;
	cin>>t;
	while(t--)
	{	int flag=1;
		ll a,b,c,d,e,f,g;
		cin>>a>>b>>c>>d>>e>>f>>g;
		for(int i=0;i<8;i++)
		{
			ll x=ss[i];
			ll a2=ff(a,x),b2=ff(b,x),c2=ff(c,x),g2=ff(g,x);
			if((mypow(a2,d,x)+mypow(b2,e,x)+mypow(c2,f,x))%x!=g2)
			{
				flag=0;
				break;
			}
		}
		
		if(flag)
		puts("Yes");	
		else 
		puts("No");
	}
	
return 0;	
}
