#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[1005][1005];
struct node
{
    int x,y,dis;
}ans[maxn];
bool cmp(node x,node y)
{
    if(x.dis!=y.dis) return x.dis<y.dis;
    else if(x.x!=y.x) return x.x<y.x;
    else return x.y<y.y;
}
int main()
{
    ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,m,k;
       cin>>n>>m>>k;
       set0(a);
       for(int i=1;i<=k;i++) 
       {
           int x,y;
           cin>>x>>y;
           a[x][y]=1;
       }
       int flag=0;
       int cnt=0;
       set0(ans);
       for(int i=1;i<=n;i++)
       {
           for(int j=1;j<m;j++)
           {
               if(a[i][j]) continue;
                if(!a[i][j]&&!a[i][j+1])
               {
                    flag=1;
                   ans[cnt].x=i;
                   ans[cnt].y=j;
                   ans[cnt].dis=abs(i-(n+1)/2)+abs(j-m/2);
                   cnt++;
               }
           }
           
       }
       if(!flag) puts("-1");
       else 
       {
            sort(ans,ans+cnt,cmp);
        printf("(%d,%d) (%d,%d)\n",ans[0].x,ans[0].y,ans[0].x,ans[0].y+1);
       }
      
   }
   //system("pause");
   return 0;
}
