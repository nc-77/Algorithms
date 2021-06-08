#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string,int>mp,tmp;
string q[15005],ans[15005];
int main()
{	mp.clear();
	tmp.clear();
	int n,sum=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		mp[s]=1;
	}
	int m,x;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s>>x;
		sum+=x;
		tmp[s]=x;
		q[i]=s;
	}
	int cnt=0;
	double ave=sum*1.0/m;
	for(int i=1;i<=m;i++)
	{
		if(tmp[q[i]]>ave&&!mp[q[i]])
		ans[cnt++]=q[i];
	}
	sort(ans,ans+cnt);
	if(cnt==0) cout<<"Bing Mei You"<<endl;
	else
	for(int i=0;i<cnt;i++)
	{
		cout<<ans[i]<<endl;
	}
	
}
