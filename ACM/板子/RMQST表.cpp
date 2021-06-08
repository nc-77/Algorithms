#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
int a[maxn],dp[maxn][35];
void stinit(int n){
    for(int i=1;i<=n;i++) dp[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
    int k=log2(r-l+1);
    int res=max(dp[l][k],dp[r-(1<<k)+1][k]);
    return res;
}

int main()
{
   //ios::sync_with_stdio(false);
   int n,q;
   cin>>n>>q;
   for(int i=1;i<=n;i++) read(a[i]);
    stinit(n);
   while(q--)
   {
       int l,r;
       read(l),read(r);
       printf("%d",query(l,r));
   }
   //system("pause");
   return 0;
}
