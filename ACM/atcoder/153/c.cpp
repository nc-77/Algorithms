#include<bits/stdc++.h>
#define ll long  long
using namespace std;
int a[300000];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	sort(a,a+n,cmp);
	ll sum=0;
	for(int i=k;i<n;i++)
	sum+=a[i];
	cout<<sum<<endl;
}
