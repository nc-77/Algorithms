#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int l0[maxn],l1[maxn],r0[maxn],r1[maxn];
int main()
{
   //ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       int n=s.size();
       int x=0,y=0;
       for(int i=0;i<n;i++)
       {
          l0[i]=x;
          l1[i]=y;
          if(s[i]=='0') x++;
          else y++;
       }
       x=0,y=0;
       for(int i=n-1;i>=0;i--)
       {
          r0[i]=x;
          r1[i]=y;
          if(s[i]=='0') x++;
          else y++;
       }
       int ans=inf;
       for(int i=0;i<n;i++)
       {
          ans=min(ans,l0[i]+r1[i]);
          ans=min(ans,l1[i]+r0[i]);
          if(s[i]=='0') ans=min(ans,l1[i]+r1[i]);
          else ans=min(ans,l0[i]+r0[i]);
       }
       cout<<ans<<endl;
    }
   //system("pause");
   return 0;
}
