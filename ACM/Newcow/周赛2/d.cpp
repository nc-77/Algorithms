#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g[maxn];
int fa[maxn];
int cnt[maxn][3];
void dfs(int u,int f)
{
    fa[u]=f;
    for(int i=0;i<g[u].size();i++)
    {
        if(g[u][i]!=f) dfs(g[u][i],u);
    }
}
int main()
{
    ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<n;i++)
   {
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   dfs(1,0);
   while(m--)
   {
       int x;
       cin>>x;
       cnt[x][0]++;
       cnt[fa[x]][1]++;
       cnt[fa[fa[x]]][2]++;
       int ans=0;
       ans+=cnt[x][1]+cnt[fa[x]][0];
       ans+=cnt[x][2]+cnt[fa[fa[x]]][0]+cnt[fa[x]][1];
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
