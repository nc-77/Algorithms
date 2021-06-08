#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e4+10;
string s[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
        int x=0,y=0;
        int s0=0,s1=0;
       for(int i=1;i<=n;i++) cin>>s[i];
       for(int i=1;i<=n;i++)
       {
           int len=s[i].size();
           if(len%2) x++;
           else y++;
           for(int j=0;j<len;j++)
           if(s[i][j]=='0') s0++;
           else s1++;
       }
       if(s0%2&&s1%2&&x==0) {
           cout<<n-1<<endl;
       }
       
       else cout<<n<<endl;
   }
   //system("pause");
   return 0;
}
