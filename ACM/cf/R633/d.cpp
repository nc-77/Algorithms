#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<int>e[maxn];
set<int>s;
map<int,int>mp;
int dis[maxn],vis[maxn];
void bfs(int s)
{
    queue<int>que;
    que.push(s);
    vis[s]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        for(int i=0;i<e[u].size();i++)
        {
            if(!vis[e[u][i]]) 
            {
                que.push(e[u][i]);
                vis[e[u][i]]=1;
                dis[e[u][i]]=dis[u]+1;
            }
        }
    }
}
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<n;i++){
       int u,v;
       cin>>u>>v;
       e[u].push_back(v);
       e[v].push_back(u);
   }
   int ans=n-1;
   for(int i=1;i<=n;i++) {
       if(e[i].size()==1)
       {
           mp[e[i][0]]++;
            if(mp[e[i][0]]>1) ans--;
       }
   }
    int s=1;
    for(int i=1;i<=n;i++){
        if(e[i].size()>1) 
        {
            s=i;
            bfs(s);
            break;
        }
    }
    int f1=0,f2=0,sum=0;
    for(int i=1;i<=n;i++){
        if(e[i].size()>1) continue;
        if(dis[i]%2==0) f1++;
        else f2++;
        sum++;
    }
    if(f1==sum||f2==sum) cout<<1<<" ";
    else cout<<3<<" ";
    cout<<ans<<endl;
   return 0;
}
