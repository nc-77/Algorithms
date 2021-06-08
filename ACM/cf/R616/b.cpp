#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[300000+10];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k=0,flag=0,minn=inf,pos=0,ans=1;
		cin>>n;
		for(int i=0;i<n;i++)
		cin>>a[i];
		for(int i=0;i<n;i++)
		{
			if(a[i]<i)
			{	
				k=i-1;
				flag=1;
				if(n>k+a[k]+1)
				{
					ans=0;
					break;
				}
			}
			if(flag) 
			{
				if(n>i+a[i]+1)
				{
					ans=0;
					break;
				}
			}
		}
		if(ans==0) puts("No");
		else puts("Yes");
	}
}
