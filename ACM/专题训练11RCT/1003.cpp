#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll m[maxn],a[maxn];
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
ll excrt(int n)
{
   ll M=m[1],A=a[1],x,y,t;
   for(int i=2;i<=n;i++)
   {
      ll d=exgcd(M,m[i],x,y);
      if((a[i]-A)%d) return -1;
      x*=(a[i]-A)/d,t=m[i]/d,x=(x%t+t)%t;
      A=M*x+A,M=M/d*m[i],A%=M;
   }
   A=(A%M+M)%M;
   return A;
}
int main()
{
   int n,aa;
   while(cin>>n>>aa)
   {    if(!n&&!aa) break;
       for(int i=1;i<=n;i++) cin>>m[i],a[i]=m[i]-aa;
       cout<<excrt(n)<<endl;
   }
   
   
   //system("pause");
   return 0;
}
