#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,minn;
int mp[200000+10][2];
int zm[2];
bool judge(int x)
{	
	minn=0;
	for(int i=0;i<n-x+1;i++)
	{	
		if(i==0)
		{
			
			minn=min(mp[i+x-1][0],mp[i+x-1][1]);
				
		}
		else
		{
				minn=min(mp[i+x-1][0]-mp[i-1][0],mp[i+x-1][1]-mp[i-1][1]);

		}
		//cout<<minn<<" "<<i<<endl;
		if(minn<=k)
		return true;
		
	}
	return false;
}
int main()
{
	
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{	zm[s[i]-'0']++;
		for(int j=0;j<=1;j++)
		mp[i][j]=zm[j];
	}

	int mid,lb=0,ub=n+1,flag=0;
	while(ub-lb>1)
	{	mid=(ub+lb)/2;
		if(judge(mid))
		{
			
			lb=mid;
			//cout<<mid<<endl; 
		}
		else ub=mid;
	}
	 cout<<lb<<endl;
	
}
