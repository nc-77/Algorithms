#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		int x,y;
		cin>>x;
		ll sum=x;
		while(x>=10)
		{
			y=x/10;
			x=x-y*10;
			x=x+y;
			sum+=y;
		}
		cout<<sum<<endl;
	}
}
