#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define ll long long
using namespace std;
struct node
{
    ll pos,val;
};
vector<node>g;
int main()
{
    ios::sync_with_stdio;
   int n,a,b;
   cin>>n>>a>>b;
   for(int i=0;i<a;i++)
   {
       ll pos,v;
       cin>>pos>>v;
       g.push_back({pos,v});
   }
   ll ans=0;ll now=0;
   for(int i=0;i<b;i++)
   {
      ll pos,v;
       cin>>pos>>v;
       while(now<g.size())
       {
           if(pos<g[now].pos) {
               break;
           }
           else if(pos==g[now].pos){
               ans+=v*g[now].val;
               now++;
               break;
           }
           else now++;
       }       
   }
   cout<<ans<<endl;
   return 0;
}
