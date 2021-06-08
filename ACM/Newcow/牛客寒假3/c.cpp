#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000000+10];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	int f1=0,f2=0;
		ll n,m,p;
		cin>>n>>m>>p;
		memset(a,0,sizeof(a));
		while(p--)
		{
			ll x,y,v;
			cin>>x>>y>>v;
			if(m*x+y<0||m*x+y>=n*m)
			f1=1;
			else a[m*x+y]=v;
			
			if(x<0||x>=n||y<0||y>=m)
			f2=1;
			
		}
		if(f1) 
		{
			cout<<"Runtime error"<<endl;
			continue;
		}
		for(int i=0;i<n*m;i++)
		{	if((i+1)%m==0)
			cout<<a[i]<<endl;
			else
			cout<<a[i]<<" ";
		}
		if(f2) cout<<"Undefined Behaviour"<<endl;
		else cout<<"Accepted"<<endl;
	}
}
