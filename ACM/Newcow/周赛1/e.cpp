#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
vector<ll>vec;
map<ll,ll>mp;
ll fac(ll n)
{ ll ans=0;
   if(n<=4) {
      return n*4;
   }
   for(int i=0;i<vec.size();i++)
   {
      if(n<=vec[i]) 
      {
         ans=mp[vec[i-1]];
         ans+=(n-vec[i-1])*vec[i];
         return ans;
      }
   }
}
signed main()
{
   ll l,r;
   cin>>l>>r;
   queue<ll>que;
   que.push(4),que.push(7);
   while(!que.empty())
   {
      ll x=que.front();
      if(x>4444444444) break;
      que.pop();
      vec.push_back(x);
      que.push(x*10+4);
      que.push(x*10+7);
      
   }
   int n=vec.size();
   mp[4]=16;
   for(int i=1;i<n;i++)
   {
      mp[vec[i]]=mp[vec[i-1]]+(vec[i]-vec[i-1])*vec[i];
   }
   cout<<fac(r)-fac(l-1)<<endl;
   //system("pause");
   return 0;
}
