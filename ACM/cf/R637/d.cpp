#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
string s,ans,dp[maxn][15];
int cost[maxn][15],mi[maxn],mx[maxn],sum[maxn][2];
int n,k,flag;
void dfs(int now,int sk,string a)
{
    if(flag) return;
    if(k-sk<sum[n][0]-sum[now-1][0]||k-sk>sum[n][1]-sum[now-1][1]) return;
    if(now==n+1&&sk==k)
    {
        ans=a;
        flag=1;
        return;
    }
    if(now==n+1) return;
    for(int i=9;i>=0;i--)
    {
        if(flag||cost[now][i]==inf||cost[now][i]+sk>k) continue;
        string ns=a+char(i+'0');
        dfs(now+1,sk+cost[now][i],ns);
       
       //debug(now),debug(sk), debug(dp[now][sk]);
    }
}
int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>k;
  string p[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
   for(int i=1;i<=n;i++)
   {
       mx[i]=-1;
       mi[i]=inf;
       cin>>s;
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<7;k++)
            {
                if(s[k]==p[j][k]) continue;
                else 
                {
                    if(s[k]=='0'&&p[j][k]=='1') cost[i][j]++;
                    else {cost[i][j]=inf;break;}
                }
            }
            if(cost[i][j]!=inf)
            {
                 mi[i]=min(mi[i],cost[i][j]);
                 mx[i]=max(mx[i],cost[i][j]);
            }
           
        }
       
   }
    for(int i=1;i<=n;i++)
    {
        if(mi[i]==inf||mx[i]==-1)
        {
            cout<<-1<<endl;
            return 0;
        }
        sum[i][0]=sum[i-1][0]+mi[i];
        sum[i][1]=sum[i-1][1]+mx[i];
    }
   //for(int i=1;i<=n;i++) for(int j=0;j<10;j++) debug(cost[i][j]);

   dfs(1,0,"");
   //debug(dp[1][0]);
    if(ans.size()!=n) cout<<-1<<endl;
        else cout<<ans<<endl;
   //system("pause");
   return 0;
}
