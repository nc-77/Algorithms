#include<iostream>
#include<queue>
#include<cstring>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int e[15][15],vis[15];
int n,m;
void dfs(int x)
{
    if(!vis[x]){
        cout<<x<<" ";
        vis[x]=1;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]&&e[x][i])
        dfs(i);
    }
}
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        cout<<cur<<" ";
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i]&&e[cur][i])
            {
                q.push(i);
                vis[i]=1;
            }
            
        }
    }
}
int main()
{
   
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
       int x,y;
       cin>>x>>y;
        e[x][y]=e[y][x]=1;
   }
    for(int i=0;i<n;i++)
    {
        if(!vis[i]){
            cout<<"{ ";
            dfs(i);
            cout<<"}"<<endl;
        }
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        if(!vis[i]){
            cout<<"{ ";
            bfs(i);
            cout<<"}"<<endl;
        }
    }
   return 0;
}
