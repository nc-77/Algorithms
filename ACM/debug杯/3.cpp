#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long 
int w[maxn],v[maxn];
int l[maxn],r[maxn],p[maxn],q[maxn];

signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       set0(l),set0(r),set0(p),set0(q);
       for(int i=1;i<=n;i++)
       {
           cin>>w[i]>>v[i];
           
           if(v[i]==1) cin>>v[i];
           
       }
       int left=m;
       for(int i=1;i<=n;i++)
       {
           l[i]=l[i-1];
           if(left>=w[i]) l[i]+=v[i],left-=w[i];
           p[i]=p[i-1];
           p[i]+=w[i];
       }
       left=m;
       for(int i=n;i>=1;i--)
       {
           r[i]=r[i+1];
           if(left>=w[i]) r[i]+=v[i],left-=w[i];
           q[i]=q[i+1];
           q[i]+=w[i];
       }
       sort(q+1,q+n+1);
      
       int ans=0;
       for(int i=0;i<=n;i++)
       {
           if(p[i]>m) break;
           int mx=m-p[i];
           int pos=upper_bound(q+1,q+n+1,mx)-q-1;
        //    debug(i),debug(mx);
        //    debug(pos);
        //    debug(l[i]);
        //    debug(r[n-pos+1]);
           ans=max(ans,l[i]+r[n-pos+1]);
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
