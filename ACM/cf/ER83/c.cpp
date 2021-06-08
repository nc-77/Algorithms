#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<int,int>mp;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {    mp.clear();
       int n;
       ll k;
       cin>>n>>k;
       int flag=1;
       for(int i=1;i<=n;i++)
       {
           ll x;
           cin>>x;
           int cnt=0;
            while(x)
            {   cnt++;
                if(x%k>1) {flag=0;break;}
                else mp[cnt]+=x%k;
                if(mp[cnt]>1) {flag=0;break;}
                x=x/k;
            }
       }
       if(flag) puts("YES");
       else puts("NO");
   }
   //system("pause");
   return 0;
}
