#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<string,int>mp;
string s[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int n;
   cin>>n;
   int ans=0;
   for(int i=1;i<=n;i++)
   {
       
       cin>>s[i];
       string t=s[i]+"/";
       string x="";
       for(int j=0;j<t.size();j++)
       {
           x+=t[j];
           if(t[j]=='/') 
           {
               mp[x]++;
               //debug(x);
           }
       }
      
   }
   for(int i=1;i<=n;i++)
   {
       int len=s[i].size();
       if(len>=4&&s[i].substr(len-4)==".eoj")
       {
           ans++;
       string t=s[i]+'/';
       if(mp[t]>1) ans--;
       }
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
