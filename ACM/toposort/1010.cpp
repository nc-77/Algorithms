#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=3e4+10;
int n,m;
int in[maxn];
vector<int>g[maxn],topo;
void toposort()
{   topo.clear();
    priority_queue <int,vector<int>,less<int> > que;
    for(int i=1;i<=n;i++)
    if(in[i]==0) que.push(i);
    while(!que.empty())
    {
        int u=que.top();
        que.pop();
        topo.push_back(u);
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            --in[v];
            if(in[v]==0) que.push(v);
        }
    }
    reverse(topo.begin(),topo.end());
}
int main()
{   ios::sync_with_stdio(false);
    int t;
    cin>>t;
    
   while(t--)
   {    
       cin>>n>>m;
       for(int i=1;i<=n;i++) g[i].clear();
       set0(in);
       while(m--)
       {
           int u,v;
           cin>>u>>v;
           swap(u,v);
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
