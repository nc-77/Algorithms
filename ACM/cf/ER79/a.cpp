#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long  r,g,b,maxx,ans;
		cin>>r>>g>>b;
		maxx=max(max(r,g),b);
		ans=r+g+b-maxx;
		if(maxx-1>ans)
		cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
 } 
