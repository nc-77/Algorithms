#include<bits/stdc++.h>
using namespace std;
int ans[1000];
int main()
{	
	int x;
	cin>>x;
	int sum=1,cnt=1;
	while(sum!=0)
	{
		if(sum<x) ans[cnt]=0;
		else
		{
			ans[cnt]=sum/x;
			sum=sum%x;
		 }
		 if(sum==0) break; 
		 sum=sum*10+1;
		 cnt++;
	}
	int flag=0;
	for(int i=1;i<=cnt;i++)
	{
		if(ans[i])
		flag=1;
		if(flag) cout<<ans[i];
	}
	cout<<" "<<cnt;
	
}
