#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll a1,a2,a3,b1,b2,b3;
	cin>>a1>>a2>>a3>>b1>>b2>>b3;
	cout<<min(a1,b2)+min(a2,b3)+min(a3,b1)<<endl;
}
