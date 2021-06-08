#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
char a[15][15];
int n,m,sx,sy,s[15][15],vis[15][15];
void dfs(int x,int y,int step)
{

    if(x==0||x==n+1||y==0||y==m+1)
    {
        printf("%d step(s) to exit\n",step);
        return;
    }
    if(vis[x][y]){
        printf("%d step(s) before a loop of %d step(s)\n",s[x][y],step-s[x][y]);
        return;
    }
    else 
    {
        vis[x][y]=1;
        s[x][y]=step;
    }
    if(a[x][y]=='N') dfs(x-1,y,step+1);
    if(a[x][y]=='S') dfs(x+1,y,step+1);
    if(a[x][y]=='E') dfs(x,y+1,step+1);
    if(a[x][y]=='W') dfs(x,y-1,step+1);
}
int main()
{
   while(cin>>n>>m)
   {
       if(!n&&!m) break;
       cin>>sy;
       for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
       set0(vis);
       dfs(1,sy,0);
   }
   //system("pause");
   return 0;
}
