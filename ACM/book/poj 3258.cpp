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
int n,c,st,a[100000+10];
bool judge(int x)
{
	int numc=n-c-1,find=0;
	while(numc--)
	{
		find=lower_bound(a+find,a+n,a[find]+x)-a;
		//cout<<find<<endl;
		if(find>=n)
		return false;
	}
	if(st-a[find]<x) return false;
	return true;
}
int main()
{	ios::sync_with_stdio(false);
	cin>>st>>n>>c;
	a[0]=0;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	n=n+1;
	sort(a,a+n);
	int lb=0,ub=st+1,mid;
	while(ub-lb>1)
	{
		mid=(lb+ub)/2;
		//cout<<lb<<" "<<ub<<" "<<mid<<endl;
		if(judge(mid))
		lb=mid;
		else
		ub=mid;
	}
	cout<<lb<<endl;
}
