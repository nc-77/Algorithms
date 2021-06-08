#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	if(b==0) 
	{
		printf("%d/0=Error",a);
		return 0;
	}
	cout<<a<<"/"; 
	if(b<0)
	cout<<"("<<b<<")";
	else
	cout<<b;
	cout<<"=";
	printf("%.2f",a*1.0/b);
}
