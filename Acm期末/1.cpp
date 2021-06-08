#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
double l,t1,t2,v1,v2;
double x,y;
int main()
{
   int n;
   cin>>n;
    
   while(n--){
       cin>>l>>t1>>t2>>v1>>v2;
        x=t1+t2+l/v1;
        y=l/v2;
        if(x<y) puts("Bike is OK!");
        else if(x>y) puts("Walk is OK!");
        else puts("Both are OK!");
   }
   return 0;
}
