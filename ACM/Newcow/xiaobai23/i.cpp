#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   string s,ans;
   cin>>s;
   ans="a";
   char mx=s[0];
   for(int i=0;i<s.size();i++) if(s[i]>mx) mx=s[i];
   string ss;
   for(int i=0;i<s.size();i++)
   {
       if(s[i]==mx) ss=s.substr(i);
       if(ss>ans) ans=ss;
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
