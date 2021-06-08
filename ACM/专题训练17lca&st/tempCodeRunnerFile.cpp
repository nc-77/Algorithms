#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int a[maxn],dp[maxn][30],n;
int dp1[maxn];//1-i 苹果数
int dp2[maxn];//i-n 苹果数
void stinit(int n){
    for(int i=1;i<=n;i++) dp[i][0]=i;
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        if(a[dp[i][j-1]]>=a[dp[i+(1<<(j-1))][j-1]]) dp[i][j]=dp[i][j-1];
        else dp[i][j]=dp[i+(1<<(j-1))][j-1];
}
int query(int l,int r){
    if(l>r) return 0;
    int k=log2(r-l+1);
    if(a[dp[l][k]]>=a[dp[r-(1<<k)+1][k]]) return dp[l][k];
    else return dp[r-(1<<k)+1][k];
}
int find(int l,int r,int x){
    if(a[query(l,r)]<=x) return -1;
    l--;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        
        if(a[query(l,mid)]>x) r=mid;
        else l=mid;
    }
    return r;
}
int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int m;
       cin>>n>>m;
       for(int i=1;i<=n;i++) cin>>a[i],dp1[i]=dp2[i]=0;
       int now=-1;
       for(int i=1;i<=n;i++){
           dp1[i]=dp1[i-1];
           if(a[i]>now) {
               now=a[i];
              dp1[i]++;
           }
       }
        stinit(n);
        dp2[n]=1;
        for(int i=n-1;i>=1;i--)
        {
            int l=i+1,r=n;
            int pos=find(l,r,a[i]);
            //debug(i),debug(pos);
            if(pos==-1) dp2[i]=1;
            else dp2[i]=dp2[pos]+1;
        }
        //for(int i=1;i<=n;i++) debug(dp2[i]);
       while(m--)
       {
           int p,q;
           cin>>p>>q;
           int ans=dp1[p-1];
           if(p==n) {
              if(q>query(1,p-1)) ans++;
           }
           else {
               if(q>a[query(1,p-1)]) ans++;
               if(a[query(p+1,n)]>q) ans+=dp2[find(p+1,n,q)];
           }
           
           cout<<ans<<endl;
       }
   }
   //system("pause");
   return 0;
}
