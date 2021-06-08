#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int a[100];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>a[8]) cnt++;
	}
	if(cnt<3||a[8]>=m*1.0*0.8)
	puts("YES");
	else puts("NO"); 
 } 
