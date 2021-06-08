#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
map<int,int>mp;
map<int,int>pre;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       mp.clear(),pre.clear();
       for(int i=1;i<=n;i++) cin>>a[i];
       int ans=inf;
       for(int i=1;i<=n;i++)
       {
           mp[a[i]]++;
           if(mp[a[i]]>=2)
            ans=min(ans,i-pre[a[i]]+1);
            pre[a[i]]=i;
       }
       if(ans==inf) puts("-1");
       else cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
