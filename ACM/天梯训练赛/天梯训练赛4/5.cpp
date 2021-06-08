#include<bits/stdc++.h>
using namespace std;
int main()
{
	double w,h;
	cin>>w>>h;
	double ans=w/(h*h);
	printf("%.1f\n",ans);
	if(ans>25) cout<<"PANG";
	else cout<<"Hai Xing";
}
