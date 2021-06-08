#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
map<string,int>mp;
int main()
{
	int n;
	while(cin>>n&&n!=0)
	{	string s,smax;
		int maxx=0;
		mp.clear();
		while(n--)
		{
			cin>>s;
			mp[s]++;
			if(mp[s]>maxx)
			{
				maxx=mp[s];
				smax=s;
			}
		}
		cout<<smax<<endl;
	}
}
