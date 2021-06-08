//bfs
int in[maxn];
vector<int>g[maxn],topo;
void toposort()
{   topo.clear();
    queue<int>que;
    for(int i=1;i<=n;i++)
    if(in[i]==0) que.push(i);
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        topo.push_back(u);
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            --in[v];
            if(in[v]==0) que.push(v);
        }
    }
    
}
//dfs
//vis=-1 表示当前正在访问
//vis=0 表示尚未访问过
//vis=1 表示已访问过
int vis[maxn],topo[maxn],t;
vector<int>g[maxn];
bool dfs(int u)
{
    vis[u]=-1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(vis[v]==-1) return false;
        else if(!vis[v]&&!dfs(v)) return false;
    }
    vis[u]=1;topo[t--]=u;
    return true;
}
bool toposort(){
    t=n;
    set0(vis);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        if(!dfs(i)) return false;
    }
    return true;
}