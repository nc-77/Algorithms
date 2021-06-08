#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e2+10;
vector<int>g[maxn],topo;
int in[maxn];
int n,m;
void toposort()
{   topo.clear();
    queue<int>que;
    for(int i=0;i<n;i++)
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
    if(topo.size()==n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
   
   while(cin>>n>>m)
   {
       if(n==0&&m==0) break;
       for(int i=0;i<n;i++) g[i].clear();
       set0(in);
       while(m--)
       {
           int u,v;
           cin>>u>>v;
           g[u].push_back(v);
           in[v]++;
       }
      toposort();
   }
   //system("pause");
   return 0;
}
