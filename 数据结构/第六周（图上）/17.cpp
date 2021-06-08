#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
vector<int>g[1050];
int vis[1050];
struct node
{
    int id,step;
};
int bfs(int x)
{
    queue<node>q;
    int sum=0;
    q.push({x,0});
    while(!q.empty())
    {
        node cur=q.front();
        q.pop();
        int step=cur.step;
        int id=cur.id;
        sum++;
        vis[id]=1;
        if(step<6)
        {
            for(int i=0;i<g[id].size();i++)
            {
                if(!vis[g[id][i]])
                {
                    vis[g[id][i]]=1;
                    q.push({g[id][i],step+1});
                }
                
            }
        }
        
    }
    return sum;
}
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<m;i++)
   {
       int x,y;
       cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
   }
   for(int i=1;i<=n;i++)
   {
       int sum=bfs(i);
       memset(vis,0,sizeof(vis));
       printf("%d: %.2f%\n",i,sum*100.0/n);
   }
   return 0;
}
