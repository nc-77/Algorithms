#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g[maxn];
int sun[maxn],par[maxn];
void dfs(int x,int fa)
{
    par[x]=fa;
    sun[par[par[x]]]++;
    for(int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(v==fa) continue;
        dfs(v,x);
    }
}
int main()
{
   //ios::sync_with_stdio(false);
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
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        int xd=g[par[i]].size()-1;
        ans+=max(xd,0);
        ans+=sun[i];
        cout<<ans<<endl;
    }

   //system("pause");
   return 0;
}
