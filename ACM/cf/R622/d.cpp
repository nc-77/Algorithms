#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
#define ls id<<1
#define rs id<<1|1
using namespace std;
const int maxn=5e5+10;
ll a[maxn],s1[maxn],s2[maxn];
stack<int>s;
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

	for(int i=1;i<=n;i++)
	{	s1[i]=s1[i-1];
		if(a[i]>=a[i-1]) s.push(i),s1[i]+=a[i];
		else
		{
			while(!s.empty()&&a[s.top()]>a[i]) 
			{
				s.pop();
				
			}
			if(!s.empty())
			s1[i]=s1[s.top()]+(i-s.top())*a[i];
			else s1[i]=a[i]*i;
			s.push(i);	
		}
	}
	while(!s.empty()) s.pop();
	for(int i=n;i>=1;i--)
	{	s2[i]=s2[i+1];
		if(a[i]>=a[i+1]) s.push(i),s2[i]+=a[i];
		else
		{
			while(!s.empty()&&a[s.top()]>a[i]) s.pop();
			if(!s.empty())
			s2[i]=s2[s.top()]+(s.top()-i)*a[i];
			else s2[i]=a[i]*(n-i+1);
			s.push(i);	
		}
	}
	ll maxx=0,maxi;
	for(int i=1;i<=n;i++)
	{
		if(s1[i]+s2[i]-a[i]>maxx)
		{
			maxi=i;
			maxx=s1[i]+s2[i]-a[i];
		}
	}
//	for(int i=1;i<=n;i++)
//	debug(s1[i]),debug(s2[i]);
//	debug(maxi); 
	for(int i=maxi-1;i>=1;i--)
	a[i]=min(a[i],a[i+1]);
	for(int i=maxi+1;i<=n;i++)
	a[i]=min(a[i],a[i-1]);
	cout<<a[1];
	for(int i=2;i<=n;i++)
	cout<<" "<<a[i];
}

