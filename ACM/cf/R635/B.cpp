#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
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
       
       int x,m,n;
       read(x),read(m),read(n);
       if(x<=n*10) x-=n*10;
       while(m)
       {
           if(x<=n*10) {
               x-=n*10;
               break;
           }
           else 
           {
               x=x/2+10;
               m--;
           }
           if(x<=n*10) {
               x-=n*10;
               break;
           }
           if(x<=0||m==0) break;
            
       }
       if(x<=0) puts("YES");
       else puts("NO");
   }
   //system("pause");
   return 0;
}
