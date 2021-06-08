#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	int flag=0;
		long long n,maxi,mini,x,a;
		cin>>n;
		cin>>x;
		for(int i=2;i<=n;i++)
		{
			cin>>a;
			if(fabs(x-a)>=2) 
			{
				flag=1;
				maxi=i;
				mini=i-1;
			}
			x=a;
		}
		if(flag) 
		{
			puts("YES");
			printf("%lld %lld\n",mini,maxi);
		}
		else puts("NO");
	}
}
