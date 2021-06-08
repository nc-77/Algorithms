#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;

double v[maxn],dp[maxn];
int w[maxn];
int main()
{
   int n,m;
   while(cin>>m>>n)
   {
       if(n==0&&m==0) break;
       for(int i=1;i<=n;i++) cin>>w[i]>>v[i],v[i]=1.0-v[i],dp[i]=1;
       dp[0]=1;
   for(int i=1;i<=n;i++)
    for(int j=m;j>=w[i];j--)
    {
         dp[j]=min(dp[j],dp[j-w[i]]*v[i]);
         debug(dp[j]);
         
    }
   
    //for(int i=1;i<=m;i++) debug(dp[i]);
    double ans=(1-dp[m])*100;
    printf("%.1f%%\n",ans);
   //system("pause");
   
   }
   return 0;
}
