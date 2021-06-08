#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
struct edge
{
    int to,cost;
};
vector<edge>g[1050];
int n,m;
int ans[1050],in[1050];
void toposort()
{
    queue<int>que;
    for(int i=0;i<n;i++){
        if(!in[i]) que.push(i);
    }
    while (!que.empty())
    {
        int cur=que.front();
        que.pop();
        for(int i=0;i<g[cur].size();i++)
        {
            int to=g[cur][i].to;
            if(--in[to]==0) que.push(to);
            ans[to]=max(ans[to],ans[cur]+g[cur][i].cost);
        }
        
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=max(res,ans[i]);
        if(in[i]) {
            cout<<"Impossible"<<endl;
            return;
        }
    }
    cout<<res<<endl;
    
}
int main()
{
   cin>>n>>m;
   while(m--)
   {
       int x,y,cost;
       cin>>x>>y>>cost;
       g[x].push_back({y,cost});
       in[y]++;
   }
   toposort();
   return 0;
}
