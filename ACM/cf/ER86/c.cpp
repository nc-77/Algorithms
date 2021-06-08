#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
 int a,b,q;
 int f(int m,int x)
 {
     int res=(m-x)/a+1;
     return res;
 }
int fac(int m)
{
    int res=0;
    if(a>b) swap(a,b);
    if(a==b||m<b) return m;
    res+=b-1;
    for(int i=0;i<b;i++)
    {
        res+=f(m,i)-f(b-1,i);
        debug(res),debug(i);
    }
    return res;
}
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
      
       cin>>a>>b>>q;
       while(q--)
       {
           int l,r;
           cin>>l>>r;
           cout<<r-l+1-(fac(r)-fac(l-1))<<endl;
       }
   }
   //system("pause");
   return 0;
}
