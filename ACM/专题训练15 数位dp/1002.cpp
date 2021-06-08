#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[200];
int dp[200][10][15][3];
int dfs(int pos,int pre,int lim,int sum,int flag)
{
    //debug(pos),debug(pre),debug(lim),debug(sum),debug(flag);
    if(pos==0)
    {
        if(flag&&sum%13==0) return 1;
        else return 0;
    }
    if(!lim&&dp[pos][pre][sum][flag]!=-1) return dp[pos][pre][sum][flag];
    int up;
    if(lim) up=a[pos];
    else up=9;
    int res=0;
    for(int i=0;i<=up;i++)
    {
        res+=dfs(pos-1,i,lim&&i==up,(sum*10+i)%13,flag||(i==3&&pre==1));
    }
    if(!lim) dp[pos][pre][sum][flag]=res;
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
    return dfs(pos,0,1,0,0);
}
signed main()
{
   //ios::sync_with_stdio(false);
   int n;
   memset(dp,-1,sizeof(dp));
   while(cin>>n)
   {
       cout<<solve(n)<<endl;
   }
   //system("pause");
   return 0;
}
