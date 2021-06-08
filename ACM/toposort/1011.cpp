#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=5e2+10;
int n,m,in[maxn];
vector<int>g[maxn],topo;
void toposort()
{   topo.clear();
    priority_queue<int,vector<int>,greater<int>>que;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0) que.push(i);
    }
    while(!que.empty())
    {
        int u=que.top();
        topo.push_back(u);
        que.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            in[v]--;
            if(in[v]==0) que.push(v);
        }

    }
}
int main()
{
   while(cin>>n>>m)
   {    for(int i=1;i<=n;i++) g[i].clear();
            set0(in);
       while(m--)
       {    
           int u,v;
           cin>>u>>v;
           g[u].push_back(v);
           in[v]++;
       }
       
    toposort();
           cout<<topo[0];
           for(int i=1;i<n;i++)
           cout<<" "<<topo[i];
           cout<<endl;
   }
   //system("pause");
   return 0;
}
