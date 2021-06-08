#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct node{
    int num;
    int d;
    bool operator<(node &a){
        return d<a.d;
    }
}a[maxn];
int vis[maxn];
vector<int>g[maxn];
bool cmp(int x,int y){
    return a[x].d<a[y].d;
}
int main()
{
   //ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=m;i++){
       int u,v;
       cin>>u>>v;
       g[u].push_back(v);
       g[v].push_back(u);
   }
   int flag=1;
   for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       a[i].num=i;
       a[i].d=x;
       if(x>g[i].size()+1) flag=0;
   }
   if(!flag) {
        cout<<-1<<endl;
            return 0;
   }
   
   for(int i=1;i<=n;i++){
       if(vis[i]) continue;
       sort(g[i].begin(),g[i].end(),cmp)
       mp[a[i].d]=1;
       for(int j=0;j<g[i].size();j++){
           vis[g[i][j]]=1;
           if(mp[a[g[i][j]].d]) {
               cout<<-1<<endl;
            return 0;
           }
       }
   }
  
   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++){
       cout<<a[i].num<<" ";
   }
   //system("pause");
   
}
