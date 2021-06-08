#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{  int sum=0,ans=0;
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			if(x==0) ans++;
			sum+=x;
 		}
 		sum+=ans;
 		if(sum==0) ans++;
 		cout<<ans<<endl;
	}
 } 
