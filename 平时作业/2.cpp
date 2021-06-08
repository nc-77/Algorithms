#include<iostream>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
int main()
{
    int a,x;
    int flag=1;
    int vis=0;
   while(cin>>a>>x)
   {
       
       if(a*x){
           if(flag){
               flag=0;
               cout<<a*x;
               vis=1;
           }
           else cout<<" "<<a*x;
       }
       if(x) cout<<" "<<x-1;

   }
   if(!vis){
       cout<<"0 0"<<endl;
   }
   return 0;
}
