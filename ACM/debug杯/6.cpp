#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
#define int long long
vector<int>g[maxn];
int p[maxn],c[maxn],flag,sum;
int  dfs(int u,int fa)
{
    int sum=0;
    for(int i=0;i<g[u].size();i++)
    {
        int to=g[u][i];
        if(to==fa) continue;
       sum+=dfs(to,u);
    }

    if(u!=1)    return max(0ll,sum+p[u]-c[u]);
    else return sum+p[u]-c[u];
}
signed main()
{ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) g[i].clear();
       for(int i=1;i<n;i++) 
       {
           int u,v;
           cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
       }
       
       for(int i=1;i<=n;i++) cin>>p[i]>>c[i];
       
       int ans=0;
       ans=dfs(1,0);
       
       if(ans>0) cout<<"NO"<<endl;
       else cout<<"YES"<<endl;
   }
   //system("pause");
   return 0;
}
