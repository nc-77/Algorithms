#include<bits/stdc++.h>
using namespace std;
double s[10000+10][15],maxx,minn;
double sum[10000+10];
bool cmp(double x,double y)
{
	return x>y;
}
int main()
{
	int n,k,m;
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
	{	maxx=0;
		minn=101;
		for(int j=0;j<k;j++)
		{
			cin>>s[i][j];
			sum[i]+=s[i][j];
			minn=min(minn,s[i][j]);
			maxx=max(maxx,s[i][j]);
		}
		sum[i]=sum[i]-maxx-minn;
		sum[i]=sum[i]/(k-2);
		
	}
	sort(sum,sum+n,cmp);
	for(int i=m-1;i>=0;i--)
	{
		if(i!=0)printf("%.3f ",sum[i]);
		else printf("%.3f",sum[i]);
	}
}
