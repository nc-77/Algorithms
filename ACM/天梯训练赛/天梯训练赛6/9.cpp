#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100000+10];
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{	cin>>a[i];
		sum+=a[i];
	}
	//cout<<sum<<endl;
	sort(a,a+n);
	int hs=0;
	if(n%2==0)
	{
		for(int i=0;i<n/2;i++)
		{
			hs+=a[i];
		}
		printf("Outgoing #: %d\n",n/2);
		printf("Introverted #: %d\n",n/2);
		printf("Diff = %d",sum-2*hs);		

	}
	else
	{
		for(int i=0;i<n/2;i++)
		{
			hs+=a[i];
		}
		printf("Outgoing #: %d\n",n/2+1);
		printf("Introverted #: %d\n",n/2);
		printf("Diff = %d",sum-2*hs);	
	}
}
