#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll gcd(ll x,ll y)
{
	return y==0? x:gcd(y,x%y);
}
int main()
{
	int n;
	cin>>n;
	ll x1,y1;
	scanf("%lld/%lld",&x1,&y1);
	n--;
	while(n--)
	{
		ll x2,y2;
		scanf("%lld/%lld",&x2,&y2);
		//cout<<x1<<y1<<x2<<y2<<endl;
		ll lcm=y1*y2/gcd(y1,y2);
		x1=x1*lcm/y1+x2*lcm/y2;
		y1=lcm;
		if(x1)
		{
			ll g=gcd(fabs(x1),fabs(y1));
			x1=x1/g;
			y1=y1/g;
		 } 
		 
	}
	if(x1)
		{
			ll g=gcd(fabs(x1),fabs(y1));
			x1=x1/g;
			y1=y1/g;
		 } 
	ll zs=x1/y1;
		 x1=x1-zs*y1;
		 
		 if(zs&&x1) 
		  
		 cout<<fabs(zs)<<" "<<x1<<"/"<<y1<<endl;
		 if(zs&&!x1) cout<<zs<<endl;
		 if(!zs&&x1) cout<<x1<<"/"<<y1<<endl;
		 else if(!zs&&!x1) cout<<"0"<<endl;
}
