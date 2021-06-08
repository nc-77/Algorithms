#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct node
{
    ll id,x;
    friend bool operator <(node z,node y)
    {
        return z.x<y.x;
    }
}a[maxn];
int te[maxn],dp[maxn],p[maxn];
signed main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i].x,a[i].id=i;
   sort(a+1,a+n+1);
   if(n<=5)
   {
       cout<<a[n].x-a[1].x<<" "<<1<<endl;
       for(int i=1;i<=n;i++)
       cout<<1<<" ";
       cout<<endl;
       return 0;
   }
   memset(dp,inf,sizeof(dp));
   dp[3]=a[3].x-a[1].x,p[3]=1;
   dp[4]=a[4].x-a[1].x,p[4]=1;
   dp[5]=a[5].x-a[1].x,p[5]=1;
  int ans=0;
  for(int i=6;i<=n;i++)
  {
      for(int j=3;j<=5&&i-j>=3;j++)
      {
        if(dp[i-j]+a[i].x-a[i-j+1].x<dp[i])
        {
            dp[i]=dp[i-j]+a[i].x-a[i-j+1].x;
            p[i]=i-j+1;
        }
      }
  }
  int cur=n,t=1;
    while(cur>0)
    {
        for(int i=cur;i>=p[cur];i--)
        {
            te[a[i].id]=t;
        }
        t++;
        ans+=a[cur].x-a[p[cur]].x;
        cur=p[cur]-1;
    }
       cout<<ans<<" "<<t-1<<endl;
   for(int i=1;i<=n;i++)
   cout<<te[i]<<" ";
   //system("pause");
   return 0;
}
