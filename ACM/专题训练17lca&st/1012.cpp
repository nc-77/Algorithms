#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
int a[maxn],p[maxn][35];
void st(int n){
    for(int i=1;i<=n;i++) p[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
        p[i][j]=max(p[i][j-1],p[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
    int k=log2(r-l+1);
    int res=max(p[l][k],p[r-(1<<k)+1][k]);
    return res;
}
int main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while (t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i];
       int m;cin>>m;
       set0(p);
       st(n);
       while(m--){
           int l,r;
           cin>>l>>r;
           cout<<query(l,r)<<endl;
       }
   }
   
   //system("pause");
   return 0;
}
