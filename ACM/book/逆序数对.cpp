#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100],bit[100],n;
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
int sum(int i)
{	int res=0;
	while(i>0)
	{
		res+=bit[i];
		i-=i&(-i);
	}
	return res;
}
int main()
{
	
	while(cin>>n)
	{	memset(bit,0,sizeof(bit));
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			ans+=i-sum(a[i]);
			add(a[i],1);
		}
		cout<<ans<<endl;
	}
 } 
