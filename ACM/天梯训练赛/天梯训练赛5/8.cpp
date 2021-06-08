#include<bits/stdc++.h>
using namespace std;
map<int,string>mp;
int main()
{
	int n,x=0,num[10000+10],sum=0,ans,i;
	cin>>n;
	for( i=0;i<n;i++)
	{
		string s;
		int x;
		cin>>s>>x;
		mp[x]=s;
		num[i]=x;
		sum+=x;
	}
	double ave=sum/n/2,minn=500;
	//cout<<ave<<endl;
	for( i=0;i<n;i++)
	{
		if(fabs(ave-num[i])<minn)
		{
			minn=fabs(ave-num[i]);
			ans=i;
		}
	}
	//cout<<ans<<endl;
	printf("%d ",(int)ave);
	cout<<mp[num[ans]]<<endl;
}
