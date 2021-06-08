#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],vis[105];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       set0(vis);
       int ans=1;
       for(int i=1;i<=n;i++) 
       {
           cin>>a[i];
           vis[a[i]]=1;
           if(vis[a[i]-1]||vis[a[i]+1]) ans=2;
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
