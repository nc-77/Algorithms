#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct node
{
   int x,y;
}a[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   string s;
   cin>>s;
   int now=0,cnt=0,flag=0;
   s+='+';
   double ans=0;
   for(int i=0;i<s.size();i++)
   {
      if(s[i]>='0'&&s[i]<='9')
      now=now*10+s[i]-'0';
      else if(s[i]=='d'){
         a[cnt].x=now;
         now=0;
         flag=1;
      }
      else if(s[i]=='+'&&flag){
         a[cnt].y=now;
         now=0;
         flag=0;
         ans+=a[cnt].x*(1+a[cnt].y)/2.0;
         cnt++;
      }
      else if(s[i]=='+'&&!flag)
      ans+=now;
   }
   if(ans==(int)ans) printf("%.0f",ans);
   else printf("%.1f",ans);
   //system("pause");
   return 0;
}
