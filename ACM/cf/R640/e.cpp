#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=8e3+10;
int a[maxn],sum[maxn],vis[maxn];
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
int  main()
{
   
   int t;
   read(t);
   while(t--)
   {
       int n;read(n);
       for(int i=1;i<=n;i++) 
       {
           read(a[i]);
           sum[i]=sum[i-1]+a[i];
           vis[a[i]]=0;
       }
       for(int i=2;i<=n;i++)
            for(int j=1;j<i;j++)
            {
                if(sum[i]-sum[j-1]<=8000) 
                 vis[sum[i]-sum[j-1]]=1;
            }
           
            int cnt=0;
        for(int i=1;i<=n;i++) if(vis[a[i]]) cnt++;
        printf("%d\n",cnt);
   }
   //system("pause");
   return 0;
}
