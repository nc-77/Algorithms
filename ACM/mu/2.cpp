#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int dp[100000];
int a[10],f[10];
int main()
{
   //ios::sync_with_stdio(false);
   f[1]=1,f[2]=2,f[3]=5;
   while(cin>>a[1]>>a[2]>>a[3])
   {
       if(!a[1]&&!a[2]&&!a[3]) break;
       memset(dp,0,sizeof(dp));
       dp[0]=1;
       for(int i=1;i<=3;i++)
        for(int j=1;j<=a[i];j++)
            for(int k=8000;k>=f[i];k--) dp[k]|=dp[k-f[i]];
       for(int i=1;i<=8000;i++)
       {
           if(!dp[i])  {
               cout<<i<<endl;
               break;
           }
           
       }
       
   }
   //system("pause");
   return 0;
}
