#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=1e5+10;
bool dp[7210];
ll a[maxn];
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       set0(dp);
       dp[0]=1;
       set<int>s;
       for(int i=1;i<=n;i++) read(a[i]),a[i]%=3600;
       for(int i=1;i<=n;i++)
       {
           s.clear();
           for(int j=3600;j>=0;j--)
           {
              dp[j]|=dp[j];
              if((j+a[i])>3600&&dp[j]) s.insert((j+a[i])%3600);
              else  dp[j+a[i]]|=dp[j];
              if(dp[3600]) break;
           }
           for(auto x:s){
               dp[x]=1;
               if(dp[3600]) break;
           }
           if(dp[3600]) break;
       }
       if(dp[3600]) puts("YES");
       else puts("NO");
   }
   //system("pause");
   return 0;
}
