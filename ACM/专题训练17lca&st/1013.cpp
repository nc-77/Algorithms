#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int a[maxn],dp[maxn][25];
void st(int n)
{
    for(int i=1;i<=n;i++) dp[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int query(int l,int r)
{
    int k=log2(r-l+1);
    int res=max(dp[l][k],dp[r-(1<<k)+1][k]);
    return res;
}
signed main()
{
   ios::sync_with_stdio(false);
   int n,k;
   while(cin>>n>>k)
   {
       if(n==-1&&k==-1) break;
       int m=0;
       int mx=0;
       for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
       int l=max(k/mx,1);
       st(n);
       for(int i=l;i<=n;i++)
       {
           int t=n/i;
           int up=t*i;
           int sum=0;
           for(int j=1;j<=up;j+=t)
           {
               sum+=query(j,j+t-1);
           }
           if(sum>k) {
               m=i;
               break;
           }
       }
       if(m) cout<<m<<endl;
       else cout<<-1<<endl;
   }
   
   //system("pause");
   return 0;
}
