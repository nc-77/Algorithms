#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int g[1050][1050];
int vis[1050];
vector<int>path;
int n;
void dfs(int s)
{
    path.push_back(s);
    vis[s]=1;
    for(int i=1;i<=n;i++){
        if(g[s][i]&&!vis[i]){
            vis[i]=1;
            
            dfs(i);
            path.push_back(s);
        }
    }
    
}
int main()
{
   int m,s;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x][y]=g[y][x]=1;
    }
    dfs(s);
    int first=0;
    int len=path.size();
    for(int i=0;i<len;i++){
       
        if(!first) cout<<path[i];
        else cout<<" "<<path[i];
        first=1;
    }
    if(len!=2*n-1) cout<<" 0";
   return 0;
}
