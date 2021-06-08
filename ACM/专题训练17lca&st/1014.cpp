#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int a[maxn],dp[maxn][35];
map<int,int>mp;
int gcd(int a,int b){
    return b? gcd(b,a%b):a;
}
void stinit(int n)
{
    for(int i=1;i<=n;i++) dp[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        dp[i][j]=gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int query_gcd(int l,int r)
{
    int k=log2(r-l+1);
    int res=gcd(dp[l][k],dp[r-(1<<k)+1][k]);
    return res;
}
int n;
int find(int s,int x)
{
    int l=s,r=n+1;
    while(r-l>1)
    {
        int mid=(r+l)/2;
        if(query_gcd(s,mid)==x) l=mid;
        else r=mid;
    }
    mp[x]+=l-s+1;
    return l;
}
signed main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   int eg=1;
   while(t--)
   {
       
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i];
       stinit(n);
       mp.clear();
       for(int i=1;i<=n;i++)
       {
           int now=i;
           while(now<=n)
           {
               now=find(now,query_gcd(i,now))+1;
           }
       }
       int q;cin>>q;
       cout<<"Case #"<<eg++<<":"<<endl;
       while(q--)
       {
           int l,r;
           cin>>l>>r;
           int ans=query_gcd(l,r);
           cout<<ans<<" "<<mp[ans];
           cout<<endl;
       }
   }
   //system("pause");
   return 0;
}
