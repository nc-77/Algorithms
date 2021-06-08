#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
int n,m,dp[maxn][10],a[maxn];
int dfs(int pos,int pre,int sta,int lim)
{
    if(pos==0) return 1;
    if(dp[pos][sta]!=-1&&!lim) return dp[pos][sta];
    int up;
    if(lim) up=a[pos];
     else up=9;
     int res=0;
     for(int i=0;i<=up;i++)
     {
         //if(i==4) continue;
         if(i==2&&pre==6) continue;
         res+=dfs(pos-1,i,i==6,lim&&i==up);
     }
     if(!lim) dp[pos][sta]=res;
     return res;
}
int solve(int x)
{
    int pos=0;
    
    while(x)
    {
        a[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,0,1);
}
signed main()
{
   //ios::sync_with_stdio(false);
   memset(dp,-1,sizeof(dp));
   while(cin>>n>>m)
   {
       if(!n&&!m) break;
        //debug(solve(m));
        cout<<solve(m)-solve(n-1)<<endl;
   }
   //system("pause");
   return 0;
}
