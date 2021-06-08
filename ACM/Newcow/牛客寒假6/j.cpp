#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	if(a>=b+c||b>=a+c||c>=a+b) 
	{
		puts("wtnl");
		return 0;
	}
	puts("Yes");
	double s[5];
	s[0]=(a+c-b)*1.0/2;
	s[1]=(a+b-c)*1.0/2;
	s[2]=(b+c-a)*1.0/2;
	sort(s,s+3);
	printf("%.2f %.2f %.2f",s[0],s[1],s[2]);
}

