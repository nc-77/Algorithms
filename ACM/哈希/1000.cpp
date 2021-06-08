#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<ll,ll>mp;
int main()
{
   //ios::sync_with_stdio(false);
   int n;
   while(cin>>n)
   {
       mp.clear();
       int x;
       int ans;
       for(int i=1;i<=n;i++)
       {
           cin>>x;
           mp[x]++;
           if(mp[x]>=(n+1)/2) ans=x;
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
