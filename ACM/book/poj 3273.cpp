#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
int n,m,a[100000+10];
bool judge(int x)
{	int sum=0,num=1;
	for(int i=1;i<=n;i++)
	{
		if(sum+a[i]<=x) sum+=a[i];
		else 
		{	
			sum=a[i];
			num++;
			if(sum>x) return false;
			//cout<<i<<" "<<num<<endl;
		}
	}
	if(num<=m)return true;
	else return false;
}
int main()
{	ios::sync_with_stdio(false);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	int lb=0,ub=sum,mid;
	while(ub-lb>1)
	{
		mid=(ub+lb)/2;
		//cout<<lb<<" "<<ub<<" "<<mid<<endl;
		if(judge(mid))
		ub=mid;
		else 
		lb=mid;
	}
	cout<<ub<<endl;
}
