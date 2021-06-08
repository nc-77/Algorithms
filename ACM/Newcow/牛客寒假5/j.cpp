#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
#define PI 3.14159265
using namespace std;
int main()
{
	int n;
	double r;
	cin>>n>>r;
	int x,y;
	cin>>x>>y;
	int a=fabs(x-y);
	a=min(a,n-a);
	//debug(a);
	//cout<<sin(PI/n)<<endl;
	double ans=a*1.0*sin(PI/n)*2*r;
	printf("%.6f",ans);
}
