#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pre[100100];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	
		string s;
		int n,x;
		ll cnt0=0,cnt1=0,ans=0,flag=0;
		cin>>n>>x;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0') cnt0++;
			else cnt1++;
			pre[i]=cnt0-cnt1;
		}
		if(x==0) ans=1; 
		if(pre[n-1]==0)
		{
			for(int i=0;i<n;i++)
			if(pre[i]==x) 
			{
				puts("-1");
				flag=1;
				break;
			}
			if(flag==0)
			puts("0");
				
		
		}
		else 
		{
			for(int i=0;i<n;i++)
			{
				if((x-pre[i])%pre[n-1]==0&&(x-pre[i])/pre[n-1]>=0)
				ans++;
			}
			cout<<ans<<endl;
			}
	}
}
