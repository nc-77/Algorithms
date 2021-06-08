#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll r[maxn],g[maxn],w[maxn];
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
   ll x,y,a,b,c;
   cin>>x>>y>>a>>b>>c;
   for(int i=1;i<=a;i++) cin>>r[i];
   for(int i=1;i<=b;i++) cin>>g[i];
   for(int i=1;i<=c;i++) cin>>w[i];
   sort(r+1,r+a+1,cmp);
   sort(g+1,g+b+1,cmp);
   sort(w+1,w+c+1,cmp);
   priority_queue <ll,vector<ll>,greater<ll> >q;
   ll sum=0;
   for(int i=1;i<=x;i++) q.push(r[i]),sum+=r[i];
   for(int i=1;i<=y;i++) q.push(g[i]),sum+=g[i];
   for(int i=1;i<=c;i++)
   {    if(q.empty()) break;
       ll mi=q.top();
       if(w[i]>mi) {
           sum+=w[i];
           sum-=mi;
           q.pop();
       }
       else break;
   }
   cout<<sum<<endl;
   //system("pause");
   return 0;
}
