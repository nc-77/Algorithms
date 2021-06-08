#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int n;
int ans[25];
int pri[]={2,3,5,7,11,13,17,19,23,29,31,37};
int vis[25],t[40];
void dfs(int x)
{
    if(x>n+1) return;
    if(x==n+1&&t[ans[n]+ans[1]]) 
    {
        for(int i=1;i<=n;i++) cout<<ans[i]<<(i==n?"\n":" ");
        
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&t[i+ans[x-1]])
        {
            vis[i]=1;
            ans[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main()
{
    for(int i=0;pri[i]!=0;i++)
    t[pri[i]]=1;
    int ca=1;
   while(cin>>n)
   {
       printf("Case %d:\n",ca++);
       ans[1]=1;
       vis[1]=1;
       dfs(2);
       printf("\n");
   }
   //system("pause");
   return 0;
}
