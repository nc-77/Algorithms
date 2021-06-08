#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
char mp[25][maxn];
int n,m,a,b;
int vis[25],flag;
set<int>s;
bool ok()
{  s.clear();
   for(int i=1;i<=n;i++)
   {
      if(vis[i]) continue;
      for(int j=1;j<=m;j++)
      if(mp[i][j]=='*') s.insert(j);
   }
   return b>=s.size();
}
void dfs(int now,int cnt)
{
   if(cnt==a&&ok()) {
      flag=1;return;
   } 
   if(flag||now>n) return;
   vis[now]=1;
   dfs(now+1,cnt+1);
   vis[now]=0;
   dfs(now+1,cnt);
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      cin>>n>>m>>a>>b;
      set0(vis);
      
      flag=0;
      for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>mp[i][j];
      dfs(1,0);
      if(flag) cout<<"yes"<<endl;
      else cout<<"no"<<endl;
   }
   //system("pause");
   return 0;
}
