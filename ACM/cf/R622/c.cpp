#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e3+10;
ll a[maxn],b[maxn],c[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    ll maxx=0,s,t=0,maxi;
    for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
			b[i]=a[i];
			c[i]=a[i];
		}
    for(int i=1;i<=n;i++) 
	{
		
		if(a[i]>maxx)
		{
			maxx=a[i];
			maxi=i;
			if(i==1) t=a[2];
			else if(i==n) t=a[n-1];
			else t=a[i-1]+a[i+1];
		}
		if(a[i]==maxx)
		{
			if(i==1&&a[2]>t)
			{
				maxi=i;
				t=a[2];
			}
			if(i==n&&a[n-1]>t)
			{
				maxi=i;
				t=a[n-1];
			}
			else if(i!=1&&i!=n&&a[i-1]+a[i+1]>t)
			{
				maxi=i;
				t=a[i-1]+a[i+1];
			}
		}
	}
	for(int i=maxi+1;i<=n;i++)
	{
		a[i]=min(a[i],a[i-1]);
	}
    for(int i=maxi-1;i>=1;i--)
	{
		a[i]=min(a[i],a[i+1]);
	}
	ll ans=0,p=a[1],q=a[n];
	for(int i=1;i<=n;i++) ans+=a[i];
	for(int i=2;i<=n;i++) 
	{
		b[i]=min(b[i],b[i-1]);
		p+=b[i];
	}
	for(int i=n-1;i>=1;i--)
	{
		c[i]=min(c[i],c[i+1]);
		q+=c[i];
	}
	ll tt=max(ans,max(q,p));
	if(tt==ans)
	{
		cout<<a[1];
	for(int i=2;i<=n;i++)
	cout<<" "<<a[i];
	}
	else if(tt==q)
	{
		cout<<b[1];
	for(int i=2;i<=n;i++)
	cout<<" "<<b[i];
	}
	else if(tt==p)
	{
		cout<<c[1];
	for(int i=2;i<=n;i++)
	cout<<" "<<c[i];
	}
}

