#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       double a,b,c,d,e;
       cin>>a>>b>>c>>d>>e;
       double per=a*a;
       double ser=b*c;
       double bel=d*e/2;
       if(per>ser&&per>bel) puts("Perch");
       else if(ser>per&&ser>bel) puts("Semon");
       else puts("Belinda");
   }
   return 0;
}
