#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=1e5+10;
const int mod=1e9+7;
ll a[maxn],b[maxn],num[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	sort(b+1,b+n+1);
	sort(a+1,a+n+1);
	if(b[n]<a[n]) 
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int pos=upper_bound(a+1,a+n+1,b[i])-a;
		num[i]=pos-1;
	}
	ll ans=1;
	for(int i=1;i<=n;i++)
	{	//debug(num[i]);
		ans=ans*(num[i]-i+1)%mod;
	}
	cout<<ans<<endl;
}

