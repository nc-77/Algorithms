#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	int flag1=0,flag2=0,ans=1;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if(x%2==1) flag1=1;
			if(x%2==0)  flag2=1;
 		}
		if(!flag2&&flag1)
		{
			if(n%2==0) ans=0;
			else ans=1;
		}
		if(flag1&&flag2) ans=1;
		if(!flag1&&flag2) ans=0;
		if(ans) puts("YES");
		else puts("NO");
	}
}
