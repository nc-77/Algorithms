#include<bits/stdc++.h>
using namespace std;

int main()
{	map<int,int>mp;
	mp.clear();
	int q,x,num,ans=0;
	cin>>q>>x;
	while(q--)
	{	cin>>num;
		mp[num%x]++;
		int need=ans/x;
		while(mp[ans%x]>need)
		{
			ans++;
			need=ans/x;
		}
		cout<<ans<<endl;
	}
 } 
