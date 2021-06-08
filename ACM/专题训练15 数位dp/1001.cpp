#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
int a[200],dp[maxn][10];
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
        if(i==9&&pre==4) continue;
        res+=dfs(pos-1,i,i==4,lim&&i==up);
    }
    if(!lim)   dp[pos][sta]=res;
    return res;
}
int solve(int x)
{
    int cnt=0;
    while(x)
    {
        a[++cnt]=x%10;
        x/=10;
    }
    return dfs(cnt,0,0,1);
}
signed main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   memset(dp,-1,sizeof(dp));
   while(t--)
   {
       int n;
       cin>>n;
       cout<<n-solve(n)+1<<endl;
   }
   //system("pause");
   return 0;
}
