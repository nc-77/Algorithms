#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll x[maxn],r[maxn];

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
        for(int i=1;i<=n;i++) read(x[i]),read(r[i]);
        ll flag=1,mx=x[1]+r[1];
        ll ans=3*(x[n]-x[1]);
        for(int i=1;i<=n-1;i++)
        {
            if(x[i+1]<=mx)
            mx=max(mx,x[i+1]+r[i+1]);
            else 
            {
                flag=0;
                break;
            }
        }
        mx=x[n]-r[n];
        for(int i=n;i>=2;i--)
        {
            if(x[i-1]>=mx)
            mx=min(mx,x[i-1]-r[i-1]);
            else 
            {
                flag=0;
                break;
            }
        }
        if(flag) cout<<ans<<endl;
        else puts("-1");
   }
   //system("pause");
   return 0;
}
