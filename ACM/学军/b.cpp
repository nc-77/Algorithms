#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],dx[maxn],dy[maxn],res;
vector<int>g[maxn];
void dfs(int now,int par,int *d)
{
    for(int i=0;i<g[now].size();i++)
    {
        int nex=g[now][i];
        if(nex==par) continue;
        d[nex]=d[now]+1;
        dfs(nex,now,d);
    }
}
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   for(int i=1;i<n;i++) 
   {
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
    dfs(1,0,dx);
    int x=0,y=0;
    for(int i=1;i<=n;i++)  if(dx[i]>dx[x]) x=i;
    set0(dx);
   dfs(x,0,dx);
   for(int i=1;i<=n;i++)  if(dx[i]>dx[y]) y=i;
   dfs(y,0,dy);
   int ans=0;
   for(int i=1;i<=n;i++)
   {
       ans=max(ans,a[i]*max(dx[i],dy[i]));
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
