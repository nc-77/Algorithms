#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],p[maxn],s[maxn],mp[maxn];
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int mxa=0,mxp=0;
       for(int i=1;i<=n;i++) cin>>a[i],mxa=max(mxa,a[i]),mp[i]=0;
        int m;cin>>m;
        for(int i=1;i<=m;i++){
           cin>>p[i]>>s[i];
           mp[s[i]]=max(mp[s[i]],p[i]),mxp=max(mxp,p[i]);
        }
        
        if(mxp<mxa) {cout<<"-1"<<endl;continue;}
         for(int i=n-1;i>=1;i--)
         {
            mp[i]=max(mp[i+1],mp[i]);
         }
         int now=1;
         int ans=0;
         while(now<=n)
         {
            int i;
            ans++;
            int mx=0;
            if(now==n) break;
            for( i=now;i<=n;i++)
            {  mx=max(mx,a[i]);
               if(mp[i-now+1]<mx)
               {
                  now=i;
                  break;
               }
            }
            if(i==n+1) break;
         }
         cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
