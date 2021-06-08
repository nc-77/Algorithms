#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))

using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
ll a[maxn],b[maxn],s[maxn];
signed main()
{ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i]>>b[i],s[i]=a[i];
       a[1]=max(0ll,a[1]-b[n]);
       ll ans=0;
       for(int i=2;i<=n;i++)
       {
           a[i]=max(a[i]-b[i-1],0ll);
           ans+=a[i];
       }
       ans+=a[1];
      ll  mx=ans-a[1]+s[1];
       for(int i=2;i<=n;i++)
       {
            mx=min(mx,ans-a[i]+s[i]);
       }
        
        cout<<mx<<endl;
   }
   //system("pause");
   return 0;
}
