#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string s;
       cin>>s;
       int len=s.size();
       s=" "+s;
       int ans=0,last=0;
       for(int i=1;i<=len;i++)
       {
           if(s[i]=='R') ans=max(ans,i-last),last=i;
           
       }
       
       ans=max(ans,len+1-last);
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
