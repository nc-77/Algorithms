#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn],c[maxn];
int n;
bool check(int x)
{
   
   string xx=to_string(x);
   for(int i=1;i<=n;i++)
   {
      int x0=x/1000,x1=x/100%10,x2=x/10%10,x3=x%10;
      map<int,int>mp;
      mp[x0]++,mp[x1]++,mp[x2]++,mp[x3]++;
      int c1=0,c2=0;
      string s=to_string(a[i]);
      for(int j=0;j<s.size();j++)
      {
         if(mp[s[j]-'0']) mp[s[j]-'0']--;
         if(xx[j]==s[j]) c2++;
      }
      for(int j=0;j<=9;j++)
      c1+=mp[j];
      //debug(c1),debug(c2);
   if(4-c1!=b[i]||c2!=c[i]) return false;
   }
   return true;
}
int main()
{
   
  while( cin>>n&&n)
   {
      for(int i=1;i<=n;i++) 
      {
         cin>>a[i]>>b[i]>>c[i];
      }
      int cnt=0,ans=0;
      for(int i=1000;i<=9999;i++)
      {
         if(check(i)) cnt++,ans=i;
      }
      if(cnt!=1) cout<<"Not sure"<<endl;
      else cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
