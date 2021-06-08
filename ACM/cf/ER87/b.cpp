#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
 string s;
 int n;
int vis[5];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      
       cin>>s;
        n=s.size();
       s=" "+s;
       int ans=inf;
       vis[1]=vis[2]=vis[3]=0;
       for(int i=1;i<=n;i++)
       {
           vis[s[i]-'0']=i;
           if(s[i]=='1'&&vis[2]&&vis[3])
           ans=min(ans,i-min(vis[2],vis[3])+1);
           if(s[i]=='2'&&vis[3]&&vis[1])
           ans=min(ans,i-min(vis[1],vis[3])+1);
           if(s[i]=='3'&&vis[2]&&vis[1])
           ans=min(ans,i-min(vis[1],vis[2])+1);
       }
       if(ans!=inf) cout<<ans<<endl;
       else cout<<0<<endl;
   }
   //system("pause");
   return 0;
}
