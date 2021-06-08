#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define ll long long
using namespace std;
int main()
{
   int n;
   cin>>n;
   while(n--){
       ll a,b,c;
       cin>>a>>b>>c;
        if(!(a<b+c&&b<a+c&&c<a+b)){
            puts("Impossible!");
        }
        else{
            if(a*a==b*b+c*c||b*b==a*a+c*c||c*c==a*a+b*b){
                puts("Right triangle");
            }
            else if(a*a>b*b+c*c||b*b>a*a+c*c||c*c>a*a+b*b){
                puts("Obtuse triangle");
            }
            else puts("Acute triangle");
        }
   }
   return 0;
}
