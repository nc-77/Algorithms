#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define pii pair<int,int>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>g[maxn];
struct node
{
    int u,v;
}ans[maxn];
map<pii,int>mp;
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n-1;i++)
   {
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
       ans[i].u=u;
       ans[i].v=v;
   }
   int cnt=0;
   for(int i=1;i<=n;i++)
   {
       if(g[i].size()==1) mp[pii(i,g[i][0])]=mp[pii(g[i][0],i)]=1,cnt++;
   }
   int tt=0;
    for(int i=1;i<=n-1;i++)
    {
        int u=ans[i].u;
        int v=ans[i].v;
        if(mp[pii(u,v)]) cout<<tt++<<endl;
        else cout<<cnt++<<endl;
    }
   //system("pause");
   return 0;
}
