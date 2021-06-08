#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
const int maxn=1e4+10;
vector<int>g[maxn];
int dis[maxn],vis[maxn];
double cal(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        //debug(dis[i]);
        sum+=dis[i];
    }
    double ans=(n-1)*1.0/sum;
    return ans;
}
void bfs(int st){
    queue<int>que;
    que.push(st);
    vis[st]=1;
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        for(int i=0;i<g[cur].size();i++){
            int to=g[cur][i];
            dis[to]=min(dis[to],dis[cur]+1);
            if(!vis[to]){
                que.push(to);
                vis[to]=1;
            }
        }
    }
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
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int st;
        cin>>st;
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        dis[st]=0;
        bfs(st);
        printf("Cc(%d)=%.2lf\n",st,cal(n));
    }
   return 0;
}
