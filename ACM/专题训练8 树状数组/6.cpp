#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
using namespace std;
const int maxn=2e5+10;
struct node
{
	int h;
	int x;
}cow[maxn];
bool cmp(node s1,node s2)
{
	return s1.h<s2.h;
}
ll jl[maxn],cnt[maxn],s[maxn];
ll sum(int i,ll *a)
{
	ll s=0;
	while(i>0)
	{
		s+=a[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,ll x,ll *a)
{
	while(i<=maxn)
	{
		a[i]+=x;
		i+=i&-i;
	}
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>cow[i].h>>cow[i].x;
    	
	}
	sort(cow+1,cow+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+cow[i].x;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll t1=sum(cow[i].x,cnt);
		ll t2=i-1-t1;
		//debug(t1),debug(t2);
		ans+=(t1*cow[i].x-sum(cow[i].x,jl))*cow[i].h;
		//debug(ans);
		ans+=((s[i-1]-sum(cow[i].x,jl))-cow[i].x*t2)*cow[i].h;
		//debug(s[i-1]),debug(sum(cow[i].x,jl));
		//debug(ans);
		add(cow[i].x,1,cnt);
		add(cow[i].x,cow[i].x,jl);
		
		
	}
	cout<<ans<<endl;
}

