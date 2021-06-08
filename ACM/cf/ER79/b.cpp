#include<bits/stdc++.h>
using namespace std;
long long a[100000+10];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,s,sum=0,maxx=0,ans,i;
		cin>>n>>s;
		for( i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for( i=1;i<=n;i++)
		{
			sum+=a[i];
			if(a[i]>maxx)
			{
				maxx=a[i];
				ans=i;
			}
			if(sum>s)
			break;
		}
		if(i==n+1) puts("0");
		else cout<<ans<<endl;
	}
}
