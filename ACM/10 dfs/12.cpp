#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
int a[maxn][maxn],p[maxn][maxn],pre[maxn][maxn],ans[maxn];
int n,m;
int dx[]={-1,0,1},dy[]={-1,-1,-1};
void dfs(int x,int y)
{
    //debug(x),debug(y);
    if(p[x][y]!=inf) return;
    if(y==1){
        p[x][y]=a[x][y];
        return;
    }
    if(x==0)
    {
        for(int i=1;i<=n;i++)
        {
            int nx=x+i,ny=y-1;
            dfs(nx,ny);
            if(p[x][y]>a[x][y]+p[nx][ny])
            {
                p[x][y]=a[x][y]+p[nx][ny];
                pre[x][y]=nx;
            }
            
            else if(p[x][y]==a[x][y]+p[nx][ny])
            pre[x][y]=min(pre[x][y],nx);
        }
    }
    for(int i=0;i<3;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>n) nx=1;
        else if(nx<1) nx=n;
        dfs(nx,ny);
       
        if(p[x][y]>a[x][y]+p[nx][ny])
             {
                p[x][y]=a[x][y]+p[nx][ny];
                pre[x][y]=nx;
            }
        else if(p[x][y]==a[x][y]+p[nx][ny])
        pre[x][y]=min(pre[x][y],nx);
       
    }
}
int main()
{
   //ios::sync_with_stdio(false);
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],p[i][j]=inf;
        memset(pre,inf,sizeof(pre));
        p[0][m+1]=inf;
        dfs(0,m+1);
        
        int x=0;
        for(int i=m+1;i>=2;i--)
        {
            ans[i-1]=pre[x][i];
            x=ans[i-1];
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<(i==m?"\n":" ");
        cout<<p[0][m+1]<<endl;
    }
   //system("pause");
   return 0;
}
