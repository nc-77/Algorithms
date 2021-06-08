#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll x,a,b,c;
		cin>>a>>b>>c>>x;
		ll sum=x+a+b+c;
		
		if(sum%3==0&&a<=sum/3&&b<=sum/3&&c<=sum/3) cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
	}
}
