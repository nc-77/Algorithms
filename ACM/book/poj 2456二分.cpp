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
int n,c,a[100000+10];
bool judge(int x)
{
	int numc=c-1,find=0;
	while(numc--)
	{
		find=lower_bound(a+find,a+n,a[find]+x)-a;
		if(find>=n)
		return false;
	}
	return true;
}
int main()
{	ios::sync_with_stdio(false);
	cin>>n>>c;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	int lb=0,ub=a[n-1]-a[0],mid;
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
