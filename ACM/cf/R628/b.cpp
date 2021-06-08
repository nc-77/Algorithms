#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
ll a[maxn];
map<ll,ll>mp;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {    mp.clear();
       int n;
       cin>>n;
       int ans=0;
       for(int i=0;i<n;i++) 
       {
           cin>>a[i];
           if(!mp[a[i]]) mp[a[i]]=1,ans++;
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
