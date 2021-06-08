#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int>mp;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		ll n,s,m,ans,ans1=0,ans2=0,t,flag1=0,flag2=0;
		cin>>n>>s>>m;
		mp.clear();
		for(int i=1;i<=m;i++)
		{
			cin>>t;
			mp[t]=1;
		}
		for(int i=s;i<=n;i++)
		{
			if(mp[i]==0)
			{
			ans1=fabs(s-i);
				flag1=1;
				break;	
				}	
			
		}
		for(int j=s;j>=1;j--)
		{
			if(mp[j]==0) 
			 {
				ans2=fabs(s-j);
				flag2=1;
				break;
			}
		}
		if(flag1&&flag2)ans=min(ans1,ans2);
		else if(flag1) ans=ans1;
		else if(flag2) ans=ans2;
		cout<<ans<<endl;
	}
 } 
