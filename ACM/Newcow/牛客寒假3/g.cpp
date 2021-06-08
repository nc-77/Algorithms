#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
const int  mod=1e9+7;
int n;
ll jl[maxn],cnt[maxn];
ll sum(int i,ll *a)
{
	ll s=0;
	while(i>0)
	{
		s+=a[i]%mod;
		i-=i&-i;
	}
	return s;
}
void add(int i,ll x,ll *a)
{
	while(i<=n)
	{
		a[i]+=x%mod;
		i+=i&-i;
	}
}
int main()
{
    //freopen("in.txt","r",stdin);
    cin>>n;
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0;i<n;i++)
    {	if(s[i]=='1')
    	{
    		ll t=sum(i+1,cnt);
    		ans+=((i+1)*t-sum(i+1,jl))%mod;
    		add(i+1,1,cnt);
    		add(i+1,i+1,jl);
		}
	}
	cout<<ans%mod<<endl;
    int q;
    cin>>q;
    while(q--)
    {
    	int ch;
    	ll x;
    	cin>>ch>>x;
    	if(ch==1)
    	{	ll t1=sum(x,cnt);
    		ll t2=sum(n,cnt)-t1;
    		ans+=(t1*x-sum(x,jl))%mod;
    		ans+=(sum(n,jl)-sum(x,jl)-t2*x)%mod;
    		add(x,1,cnt);
    		add(x,x,jl);
		}
		else if(ch==2)
		{
			ll t1=sum(x-1,cnt);
    		ll t2=sum(n,cnt)-t1-1;
    		//debug(t1),debug(t2);
    		ans-=(t1*x-sum(x-1,jl))%mod;
    		//debug(sum(x,jl));
    		//debug(ans);
    		ans-=(sum(n,jl)-sum(x,jl)-t2*x)%mod;
    		//debug(ans);
    		add(x,-1,cnt);
    		add(x,-x,jl);
		}
		cout<<ans%mod<<endl;
	}
}

