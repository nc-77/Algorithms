#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int mix(int x)
{
    int res=11;
    if(x==0) return 0;
    while(x)
    {
        res=min(res,x%10);
        x/=10;
    }
    return res;
}
int maxx(int x)
{
    int res=0;
    if(x==0) return 0;
    while(x)
    {
        res=max(res,x%10);
        x/=10;
    }
    return res;
}
signed main()
{
   ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int a,k,b;
       cin>>a>>k;
       k--;
       while(k--)
       {
           b=a+maxx(a)*mix(a);
           if(b==a) break;
           else {
               a=b;
           }
       }
       cout<<a<<endl;
   }
   //system("pause");
   return 0;
}
