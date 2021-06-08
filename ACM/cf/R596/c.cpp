#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll lowbit(ll n){return n&(-n);};
bool check(ll x,int num)
{
    int cnt=0;
    ll t=x;
    while(x)
    {
        x-=lowbit(x);
        cnt++;
    }
    if(num>=cnt&&num<=t) return true;
    return false;
}
int main()
{
   ll n,p;
   cin>>n>>p;
   int ans=-1;
   for(int i=0;i<=30;i++)
   {
       ll temp=n-i*p;
       if(check(temp,i))
       {
           ans=i;
           break;
       }
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
