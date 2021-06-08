#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		ll num=0,ans=0,flag=0;
		for(int i=0;i<n;i++)
		{
			if(i!=n-1&&s[i]=='A'&&s[i+1]=='P')
			{
				flag=1;
				num=0;
			 } 
			 if(flag&&s[i]=='P')
			 {
			 	num++;
			 	ans=max(ans,num);
			 	if(s[i+1]=='A') flag=0;
			 }
			 
		}
		cout<<ans<<endl;
	 } 
}

