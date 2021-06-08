#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=50000+10;
int bit[maxn],n;
int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&(-i);
	}
}
int main()
{	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{	memset(bit,0,sizeof(bit));
		cout<<"Case "<<j<<":"<<endl;
		cin>>n;
		for(int i=1;i<=n;i++)
		{	int x;
			cin>>x;
			add(i,x);
		}
		string s;
		while(cin>>s)
		{
			if(s=="End") break;
			int x,y;
			cin>>x>>y;
			if(s=="Query")
			cout<<sum(y)-sum(x-1)<<endl;
			if(s=="Add")
			add(x,y);
			if(s=="Sub")
			add(x,-y);
		}
	}
} 
