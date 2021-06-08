#include<bits/stdc++.h>
using namespace std;
#define p 1000;
int main()
{	long long a,b;
	while(cin>>a>>b&&a!=0||b!=0)
	{	 
		long long ans=1;
		for(;b;b=b>>1)
		{	if(b&1) ans=ans*a%p; 
			a=a*a%p;
		}
		cout<<ans<<endl;
	}
return 0;	
}
