#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll a[3];
	for(int i=0;i<3;i++)
	cin>>a[i];
	sort(a,a+3);
	cout<<a[0]<<"->"<<a[1]<<"->"<<a[2]<<endl;
}
