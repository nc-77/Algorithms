#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int w[maxn],v[maxn],vis[30];
int n,k,m,ans;
void dfs(int x,int cnt,int sum,int sw)
{
    if(cnt>k||x>n+1) return;
    if(sw>m) return;
    if(cnt==k) 
    {
        ans=max(ans,sum);
        return;
    }
    dfs(x+1,cnt+1,sum+v[x],sw+w[x]);
    dfs(x+1,cnt,sum,sw);
}
int main()
{ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       
       cin>>n>>k;
       for(int i=1;i<=n;i++)
       cin>>v[i]>>w[i];
       cin>>m;
       ans=0;
       dfs(1,0,0,0);
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
