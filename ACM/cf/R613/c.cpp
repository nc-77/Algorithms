#include<bits/stdc++.h> 
#define ll long long
using namespace std;
long long  INF=1000000000000+1;
int main()
{
	ll x,y,i;
	cin>>x;
	ll maxx=sqrt(x),m=INF,ans1,ans2;
	for( i=maxx;i>=1;i--)
	{
		if(x%i==0)
		{	 y=x/i;
			if(__gcd(i,y)==1)
			{	
				
					ans1=i;
					ans2=y;
					break;
					
			}
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
}
