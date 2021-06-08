#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i];
       int ans=0,mx=a[1],f=0;
       if(a[1]>0) f=0;
       else f=1;
       if(a[n]>0) a[n+1]=-1;
       else a[n+1]
       for(int i=2;i<=n+1;i++)
       {
            if(!f&&a[i]<0)
            {
                ans+=mx;
                mx=a[i];
                f=1;
            } 
            else if(f&&a[i]>0) 
            {
                ans+=mx;
                mx=a[i];
                f=0;
            }
           mx=max(a[i],mx);
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
