#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<string,int>vis;
struct node{
    string s;
    int len;
    bool operator<(const node &t){
        return len<t.len;
    }
};
vector<node>g;
int main()
{
   //ios::sync_with_stdio(false);
   int k,n;
   cin>>k>>n;
   for(int i=1;i<=n;i++)
   {
       string s;
       cin>>s;
       if(!vis[s]) {
           vis[s]=1;
           g.push_back({s,s.size()});
       }
   }
   sort(g.begin(),g.end());
   int ans=0;
   if(k>=g[0].len) {
           k-=g[0].len;
           ans++;
       }
   for(int i=1;i<g.size();i++)
   {
    //    debug(g[i].s);
    //    debug(g[i].len);
    //    debug(k);
       if(k>=g[i].len+1) {
           k-=g[i].len+1;
           ans++;
       }
       else break;
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
