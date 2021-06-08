#include<bits/stdc++.h>
#define ll long  long
using namespace std;
int main()
{	ll x=1;
	ll h;
	ll sum=0;
	cin>>h;
	while(h)
	{
		h=h/2;
		sum+=x;
		x=x*2;
	 } 
	 cout<<sum<<endl;
}
