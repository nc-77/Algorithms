#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,maxx;
int mp[200000+10][30];
int zm[30];
bool judge(int x)
{	
	maxx=0;
	for(int i=0;i<n-x+1;i++)
	{	maxx=0;
		if(i==0)
		{
			for(int j=0;j<26;j++)
			{
			maxx=max(maxx,mp[i+x-1][j]);
			}	
		}
		else
		{
			for(int j=0;j<26;j++)
			{
			maxx=max(maxx,mp[i+x-1][j]-mp[i-1][j]);
		
			}
		}
		//cout<<x<<" "<<maxx<<endl;
		if(maxx>=k)
		return true;
		
	}
	return false;
}
int main()
{
	
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{	zm[s[i]-'a']++;
		for(int j=0;j<26;j++)
		mp[i][j]=zm[j];
	}

	int mid,lb=0,ub=n+1,flag=0;
	while(ub-lb>1)
	{	mid=(ub+lb)/2;
		if(judge(mid))
		{
			flag=1;
			ub=mid;
			//cout<<mid<<endl; 
		}
		else lb=mid;
	}
	if(flag) cout<<ub<<endl;
	else puts("-1");
}
