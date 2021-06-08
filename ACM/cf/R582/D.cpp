#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
int fac(int x,int y)
{
    int res=0;
    if(x==y) return res;
    while(1){
        x=x/2;
        res++;
        if(x==y) return res;
        if(x<y) return -1;
    }
}
map<ll,ll>mp;
map<ll,ll>vis;
int main()
{
   //ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   for(int i=1;i<=n;i++) cin>>a[i];
   sort(a+1,a+n+1);
   int ans=0,mi=inf;
   for(int i=1;i<=n;i++){
       int cnt=0;
       for(int j=a[i];j>=0;j/=2)
       { 
           if(vis[j]<m) mp[j]+=cnt;
            vis[j]++;
           cnt++;
           if(j==0) break;
       }
   }
    for(auto x:mp){
        int t=x.second;
        int id=x.first;
        //debug(x.first),debug(t),debug(vis[id]);
        if(vis[id]>=m)mi=min(mi,t);
    }
    cout<<mi<<endl;
   
  
   //system("pause");
   return 0;
}
