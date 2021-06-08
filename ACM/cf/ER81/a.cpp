#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int len1=n/2;
		if(n%2==1) cout<<'7';
		else cout<<'1';
		for(int i=0;i<len1-1;i++)
		{
			cout<<'1';
		}
		cout<<"\n";
	}
} 
