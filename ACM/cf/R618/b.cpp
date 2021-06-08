#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int a[200000+10];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		for(int i=1;i<=n*2;i++)
		cin>>a[i];
		sort(a+1,a+n*2+1,cmp);
		
		cout<<a[n]-a[n+1]<<endl;
	}
 } 
