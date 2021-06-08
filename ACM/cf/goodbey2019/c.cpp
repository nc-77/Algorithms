#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long sum=0,x=0,a,ans1,a1,a2;
		while(n--)
		{
			cin>>a;
			sum+=a;
			x=x xor a;
		}
		if(sum==2*x) 
		{
			puts("0");
			printf("\n");
		}
		
		else 
		{
			a1=x;
			a2=sum+x;
			puts("2"); 
			printf("%lld %lld\n",a1,a2);
		}
	}
}
