#include<bits/stdc++.h>
#define ll long long
//#define int long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;


const int inf=0x3f3f3f3f;
const int maxn=2e6+10;

map<ll,ll>prime;
map<ll,ll>vis;
struct node{
    int x;
    int y;
}g[maxn];
void fac(ll n)
{
    prime.clear();
    for(int i=2;i<=n/i;i++)
    { 
          while(n%i==0)
        {
            prime[i]++;
            n=n/i;
        }
    }
    if(n>1) prime[n]++;
    for(auto t:prime){
        int x=t.first;
        int num=prime[x];
       
           vis[x]++;
           if(num<=g[x].x) {
               g[x].y=g[x].x;
               g[x].x=num;
               
           }
           else if(num<=g[x].y){
               g[x].y=num;
           }
    }
}
int a[maxn];
ll quickpow(ll x,ll n)
{
	ll res=1;
	while(n)
	{
		if(n&1) res=res*x;
		x=x*x;
		n>>=1;
	}
	return res;
}
signed main()

{
   //ios::sync_with_stdio(false);
   int n;
   cin>>n;
   int mx=0;
   for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
   for(int i=1;i<=mx;i++) g[i].x=g[i].y=inf;
   for(int i=1;i<=n;i++){
       fac(a[i]);
   }
   ll ans=1;
   for(auto t:vis){
       int x=t.first;
      // debug(x),debug(vis[x]),debug(g[x].x),debug(g[x].y);
       if(vis[x]<=n-2) continue;
       if(vis[x]==n-1)  ans=ans*quickpow(x,g[x].x);
       else ans=ans*quickpow(x,g[x].y);
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
