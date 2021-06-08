#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
       int a,b,c,d;
       cin>>a>>b>>c>>d;
       int fz=a*c;
       int fm=b*d;
       int gcd=__gcd(fz,fm);
       //debug(gcd);
       cout<<fz/gcd<<" "<<fm/gcd<<endl;
   }
   return 0;
}
