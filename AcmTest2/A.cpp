#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define ll long long
using namespace std;
int main()
{
   ll n;
  
   while(cin>>n&&n){
        ll a=1,b=1,c=1,d=1;
       while(!(n%2)){
           a++;
           n/=2;
       }
       while(!(n%3)){
           b++;
           n/=3;
       }
       while(!(n%5)){
           c++;
           n/=5;
       }
       while(!(n%7)){
           d++;
           n/=7;
       }
       cout<<a*b*c*d<<endl;
   }
   return 0;
}
