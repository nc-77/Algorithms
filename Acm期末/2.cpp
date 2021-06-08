#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
   int t;
   cin>>t;
   int a,b,c;
   for(int i=1;i<=t;i++)
   {
       cin>>a>>b>>c;
       if(c>=a+b||b>=a+c||a>=b+c){
           printf("Case #%d: invalid!\n",i);
       }
       else if(a==b&&a==c) {
           {
               printf("Case #%d: equilateral\n",i);
           }
       }
       else if(a==b||a==c||b==c){
           printf("Case #%d: isosceles\n",i);
       }
       else printf("Case #%d: scalene\n",i);
   }
   
   return 0;
}
