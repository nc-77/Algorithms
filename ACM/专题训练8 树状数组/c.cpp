#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+10;
ll bit[maxn],n;
ll sum(int i)
{
	ll s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
} 
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
struct node
{
	int value,num;
}a[maxn];
ll b[maxn];
bool cmp(node x,node y)
{
	return x.value<y.value;
}
int main()
{
	while(cin>>n)
	{	memset(bit,0,sizeof(bit));
		ll ans=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].value;
		a[i].num=i;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		b[a[i].num]=i+1;
	}
	for(int i=0;i<n;i++)
	{
		ans+=i-sum(b[i]);
		add(b[i],1);
	}
	cout<<ans<<endl;
	}
	
}
