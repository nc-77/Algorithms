#include<bits/stdc++.h>
#define ll long  long
using namespace std;
int main()
{
	ll h,n,x,sum=0;
	cin>>h>>n;
	while(n--)
	{
		cin>>x;
		sum+=x;
	}
	if(sum>=h) puts("Yes");
	else puts("No");
}
