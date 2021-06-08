#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,a,b;
	cin>>n>>x>>a>>b;
	double y=x*1.0/100;
	double ans=y*a+(1-y)*b;
	printf("%.2f",ans*n);
 } 
