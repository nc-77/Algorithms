#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int w[maxn],p[maxn],dp[maxn];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int x,y;
       cin>>x>>y;
       memset(dp,inf,sizeof(dp));
       x=y-x;
       int n;cin>>n;
       dp[0]=0;
       for(int i=1;i<=n;i++) cin>>p[i]>>w[i];
        for(int i=1;i<=n;i++)
            for(int j=w[i];j<=x;j++)
            {
                dp[j]=min(dp[j],dp[j-w[i]]+p[i]);
                
            }
        if(dp[x]==inf) cout<<"This is impossible."<<endl; 
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[x]);
   }
   //system("pause");
   return 0;
}
