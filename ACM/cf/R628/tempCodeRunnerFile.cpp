#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g[maxn];
map<ll,ll>mp;
int a[maxn],ans[maxn];
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n-1;i++)
   {
       int u,v;
       cin>>u>>v;
       if(u>v) swap(u,v);
       g[u].push_back(v);
       a[i]=v;
       mp[v]=1;
   }
   for(int i=0;i<=n;i++) ans[i]=-1;
   int cnt=0;
   for(int i=1;i<=n;i++)
   {
       if(g[i].size()==0) ans[i]=cnt++;
   }
   for(int i=1;i<=n;i++)
   {
       if(ans[i]==-1&&mp[i]) ans[i]=cnt++;
   }
    for(int i=1;i<=n-1;i++)
    cout<<ans[a[i]]<<endl;
   //system("pause");
   return 0;
}
