#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,a;
	cin>>n;
	int x=0,y=0;
	while(n--)
	{
		cin>>a;
		if(a%2==0) x++;
		else y++;
	}
	cout<<y<<" "<<x<<endl;
}
