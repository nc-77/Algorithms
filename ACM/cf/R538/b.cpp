#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn],b[maxn];
map<ll,int>mp;
bool cmp(ll x,ll y){
    return x>y;
}
int main()
{
   int n,m,k;
   cin>>n>>m>>k;
   for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
   sort(b+1,b+n+1,cmp);
   ll ans=0;
   for(int i=1;i<=m*k;i++)
   mp[b[i]]++,ans+=b[i];
   int cnt=0;
   cout<<ans<<endl;
   int f=0;
   for(int i=1;i<=n;i++)
   {
       if(mp[a[i]])
       {
           cnt++;
           mp[a[i]]--;
       }
       if(cnt==m)
       {
           cnt=0;
           f++;
          if(f!=k) cout<<i<<" ";
       }
   }
   //system("pause");
   return 0;
}
