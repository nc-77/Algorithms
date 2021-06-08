#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
ll a[maxn],r[maxn],g[maxn],b[maxn],ans;
ll fac(ll x,ll y,ll z)
{
   return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}
void work(ll *r,ll *g,ll *b,ll cr,ll cg,ll cb,int flag)
{
   ll y,z;
      for(int i=1;i<=cr;i++)
      {
         ll x=r[i];
         
            y=lower_bound(g+1,g+cg+1,x)-g;
            if(y>cg) y=cg;
            if(y>1&&x-g[y-1]<g[y]-x) y--;
            z=lower_bound(b+1,b+cb+1,x)-b;
            if(z>cb) z=cb;
            if(z>1&&x-b[z-1]<b[z]-x) z--;
         if(i==1&&flag) ans=fac(x,g[y],b[z]);
         else ans=min(ans,fac(x,g[y],b[z]));
         //debug(ans);
      }

}
signed main()
{ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      int cr,cg,cb;
      cin>>cr>>cg>>cb;
      for(int i=1;i<=cr;i++) cin>>r[i];
      for(int i=1;i<=cg;i++) cin>>g[i];
      for(int i=1;i<=cb;i++) cin>>b[i];
      sort(r+1,r+cr+1);
      sort(g+1,g+cg+1);
      sort(b+1,b+cb+1);
      
      work(r,g,b,cr,cg,cb,1);
      work(g,r,b,cg,cr,cb,0);
      work(b,r,g,cb,cr,cg,0);
      cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
