#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define int long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
signed main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int n,k;
      cin>>n>>k;
      string s;
      cin>>s;
      int last=0;
      for(int i=0;i<n;i++)
      {
         if(s[i]=='0'&&k>=i-last) 
         {
            swap(s[i],s[last]);
            k-=(i-last);
            last++;
         }
         else if(s[i]=='0')
         {
            swap(s[i],s[i-k]);
            break;
         }
      }
      cout<<s<<endl;
   }
   //system("pause");
   return 0;
}
