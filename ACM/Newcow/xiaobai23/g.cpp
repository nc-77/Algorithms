#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g[maxn];
int size[maxn];
void dfs(int u,int fa)
{
    size[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int to=g[u][i];
        if(to==fa) continue;
        dfs(to,u);
        size[u]+=size[to];
    }
}
int e[maxn];
bool cmp(int x,int y)
{
    return x>y;
}
signed main()
{
   int n;
   cin>>n;
   for(int i=1;i<n;i++)
   {
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs(1,0);
   //for(int i=1;i<=n;i++) debug(i),debug(size[i]);
   //system("pause");
   for(int i=1;i<=n;i++) e[i]=size[i]*(n-size[i]);
   sort(e+1,e+n+1,cmp);
   int ans=0,x=1;
   for(int i=1;i<n;i++) ans+=e[i]*x,x++;
   cout<<ans<<endl;
   return 0;
}
