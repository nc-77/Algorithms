#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k1,k2,max1=0,max2=0,a,b;
		cin>>n>>k1>>k2;
		while(k1--)
		{
			cin>>a;
			max1=max(max1,a);
		}
		while(k2--)
		{
			cin>>b;
			max2=max(max2,b);
		}
		if(max1>max2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
return 0;
} 
