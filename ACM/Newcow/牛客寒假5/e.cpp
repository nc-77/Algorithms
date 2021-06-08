#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
	ll n;
	cin>>n;
	int flag=1;
	while(n>=2)
	{
		if(n%2==1)
		{
			flag=0;
			break;
		}
		n=n/2;
	}
	if(!flag) puts("Bob");
	else puts("Alice"); 
 } 
