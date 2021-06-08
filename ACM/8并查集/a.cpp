#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int par[maxn];
void init(int n){
    for(int i=1;i<=n;i++) par[i]=i;
}
int find(int x){
    if(x==par[x]) return x;
    return par[x]=find(par[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    par[x]=y;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
       cin>>n>>m;
       init(n);
       for(int i=1;i<=m;i++) {
           int x,y;
           cin>>x>>y;
           unite(x,y);
       }
       int ans=0;
    for(int i=1;i<=n;i++){
        if(i==par[i]) ans++;
    }
    cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
