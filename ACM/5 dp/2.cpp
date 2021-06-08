#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
int dp[maxn][15],a[maxn][15],f[maxn][15];
int main()
{   int n;
   while(cin>>n&&n)
   {
        set0(dp),set0(a),set0(f);
        int tt=0,ans=0;
        for(int i=1;i<=n;i++)
        {   int t,pos;
            scanf("%d%d",&pos,&t);
            a[t][pos]++;
            tt=max(tt,t);
        }
        f[0][5]=1;
        for(int i=1;i<=tt;i++)
            for(int j=0;j<=10;j++)
            {   if(j==0) 
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1]);
                if(dp[i][j]==dp[i-1][j]&&f[i-1][j]) f[i][j]=1;
                 if(dp[i][j]==dp[i-1][j+1]&&f[i-1][j+1]) f[i][j]=1;
            }
                else if(j==10)
                {
                    dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
                    if(dp[i][j]==dp[i-1][j-1]&&f[i-1][j-1]) f[i][j]=1;
                 if(dp[i][j]==dp[i-1][j]&&f[i-1][j]) f[i][j]=1;
                }
                
                else 
                {
                    dp[i][j]=max(dp[i-1][j+1],max(dp[i-1][j-1],dp[i-1][j]));
                    if(dp[i][j]==dp[i-1][j]&&f[i-1][j]) f[i][j]=1;
                 if(dp[i][j]==dp[i-1][j+1]&&f[i-1][j+1]) f[i][j]=1;
                 if(dp[i][j]==dp[i-1][j-1]&&f[i-1][j-1]) f[i][j]=1;
                }
                 dp[i][j]+=a[i][j];
                 //debug(i),debug(j),debug(dp[i][j]),debug(f[i][j]);
               if(f[i][j]) ans=max(ans,dp[i][j]);
            }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
