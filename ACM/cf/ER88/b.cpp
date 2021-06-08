#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
char a[150][1050];
int vis[150][1050];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,m,x,y;
       cin>>n>>m>>x>>y;
       set0(vis);
       set0(a);
       int cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++) {
                cin>>a[i][j];
                if(a[i][j]=='.') cnt++;
            }
        int ans=0;
        if(2*x<=y){
            cout<<cnt*x<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(vis[i][j]) continue;
                if(a[i][j]=='.'&&a[i][j+1]=='.') {
                    ans+=y;
                    vis[i][j]=vis[i][j+1]=1;
                }

            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(!vis[i][j]&&a[i][j]=='.') ans+=x;
            }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
