#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int a,b,c;
       cin>>a>>b>>c;
       if(a==0&&b==0){
           for(int i=1;i<=c+1;i++) cout<<1;
           cout<<endl;
           continue;
       }
       else if(b==0&&c==0){
           for(int i=1;i<=a+1;i++) cout<<0;
           cout<<endl;
           continue;
       }
       else{
           b--;
           if(b%2==0) {
               for(int i=1;i<=b/2;i++) cout<<"01";
           }
           else {
               for(int i=1;i<=b;i++) {
                   if(i%2) cout<<1;
                   else cout<<0;
               }
           }
           for(int i=1;i<=a+1;i++) cout<<0;
           for(int i=1;i<=c+1;i++) cout<<1;
           cout<<endl;
       }
   }
   //system("pause");
   return 0;
}
