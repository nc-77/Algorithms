#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int dp[maxn];
int main()
{
   int n=3;
   int w[4]={0,150,200,350};

   for(int i=1;i<=3;i++)
   {
       for(int j=w[i];j<=10000;j++)
       {
           dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
       }
   }
   int t;
   cin>>t;
   while(t--)
   {
       int x;
       cin>>x;
        cout<<x-dp[x]<<endl;
   }
   //system("pause");
   return 0;
}
