#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[100000+10];
int vis[100000];
int num[100];
void fun(int x,int i)
{	int cnt=1;
	while(x)
	{
		if(x%2==1) 
		{
			num[cnt]=i;
			vis[cnt]++;
		}
		
		x=x/2;
		cnt++;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		fun(a[i],i);
		
	}
	int ans=0;
	for(int i=100;i>0;i--)
	{
		if(vis[i]==1)
		{
			ans=num[i];
			break;
		}
	}
	cout<<a[ans];
	for(int i=0;i<n;i++)
	{
		if(i!=ans)
		cout<<" "<<a[i];
	}
	
}
