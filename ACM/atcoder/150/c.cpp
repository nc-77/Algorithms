#include<bits/stdc++.h>
using namespace std;
long long f(int n)
{	long long ans=1;
	
	for(int i=1;i<=n;i++)
	ans=ans*i;
return ans;
}
int main()
{
	int n,a[10],b[10];
	cin>>n;
	int sum=n-1;
	long long ans1=0,ans2=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{	sum=a[i]-1;
		for(int j=1;j<i;j++)
		
			
		if(a[j]<a[i])
		{
			sum--;
		}
		//cout<<sum<<endl;
		ans1+=sum*f(n-i);
	}
	//cout<<ans1<<endl;
	for(int i=1;i<=n;i++)
	{	sum=b[i]-1;
		for(int j=1;j<i;j++)
		if(b[j]<b[i])
		{
			sum--;
		}
		ans2+=sum*f(n-i);
	}
	//cout<<ans2<<endl;
	long long ans=fabs(ans1-ans2);
	cout<<ans<<endl;
 } 
