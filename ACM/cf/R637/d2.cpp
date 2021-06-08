#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
string s,ans;
int cost[maxn][15],dp[maxn][4040];
int n,mk,flag;

int main()
{
   ios::sync_with_stdio(false);
   cin>>n>>mk;
  string p[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
   for(int i=1;i<=n;i++)
   {
       
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
            
        }
       
   }
   dp[n+1][0]=1;
    for(int i=n;i>=1;i--)
        for(int j=0;j<10;j++)
        {
            if(cost[i][j]==inf) continue;
            for(int k=0;k<=mk;k++)
             dp[i][k+cost[i][j]]|=dp[i+1][k];
        }
        if(!dp[1][mk]) {cout<<-1<<endl;return 0;} 
    string ans;
    int now=mk;
    for(int i=1;i<=n;i++)
        for(int j=9;j>=0;j--)
        {
            if(now>=cost[i][j]&&dp[i+1][now-cost[i][j]]) 
            {
                now-=cost[i][j];
                ans+=char(j+'0');
                break;
            } 
        }
        cout<<ans<<endl;
   return 0;
}
