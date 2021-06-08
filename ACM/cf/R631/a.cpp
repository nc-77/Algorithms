#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
int vis[maxn];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,x,m;
       cin>>n>>x;
       set0(vis);
        int cnt=0,t=x;
       for(int i=1;i<=n;i++) cin>>m,vis[m]=1;
       for(int i=1;i<=100;i++) if(vis[i])cnt++;
       int ans=0;
       for(int i=1;i<=100;i++)
       {
           if(!vis[i])
           {
               if(x>0) x--;
               else {break;}
           }
           ans=i;
       }
       if(cnt+t>=100) ans=cnt+t;
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
