#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int n,a[20][20],ans[20];
int vis[30][5],cnt;//0 行 1 列 2 左对角 3右对角
bool judge(int x,int y)
{
    if(vis[y][1]||vis[x-y+n][2]||vis[x+y][3]) return false;
    return true;
}
void dfs(int x)
{
    if(x==n+1)
    {
         cnt++;
        if(cnt<=3)
        {
            for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
            cout<<endl;
        }
       
    }
    for(int i=1;i<=n;i++)
    {
        if(judge(x,i))
        {
            //vis[x][0]=1;
            vis[i][1]=vis[x-i+n][2]=vis[i+x][3]=1;
            ans[x]=i;
            dfs(x+1);
            vis[i][1]=vis[x-i+n][2]=vis[i+x][3]=0;
        }
    }
}
int main()
{
   cin>>n;
   dfs(1);
   cout<<cnt<<endl;
   //system("pause");
   return 0;
}
