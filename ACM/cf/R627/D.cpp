#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define rank rk
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn],b[maxn],c[maxn],d[maxn];
int bit[maxn];
map<ll,ll>rank;
int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=maxn)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}

int main()
{
   int n;
   cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=1;
    for(int i=1;i<=n;i++) 
    {
        cin>>b[i],c[i]=a[i]-b[i];
        d[cnt++]=c[i],d[cnt++]=-c[i];
    }
    sort(d+1,d+cnt);
    int num=unique(d+1,d+cnt)-d;
    for(int i=1;i<num;i++) rank[d[i]]=i;
    add(rank[-c[n]],1);
    ll ans=0;
    for(int i=n-1;i>=1;i--)
    {
        ans+=sum(rank[c[i]]-1);
        add(rank[-c[i]],1);
    }
    //sort(e+1,e+cnt,cmp);
   //system("pause");
   cout<<ans<<endl;
   return 0;
}
