#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
	int t,cnt=1;
	cin>>t;
	while(t--)
	{	ll x,sum=0,maxx=-inf,st=0,ed=0,temp=0;
		int num;
		cin>>num;
		for(int i=0;i<num;i++)
		{
			cin>>x;
			sum+=x;
			if(sum>maxx)
			{	st=temp;
				maxx=sum;
				ed=i;
			}
			if(sum<0) 
			{
				temp=i+1;
				sum=0;
			}
			
		}
		
		printf("Case %d:\n%d %d %d\n",cnt++,maxx,st+1,ed+1);
		if(t!=0) printf("\n");
	}
}
