#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int a,b;
   cin>>a>>b;
   if(b-a==1) cout<<a<<" "<<b;
   else if(a==b) cout<<a*10<<" "<<b*10+1;
   else
   {
       if(a==9&&b==1) 
       cout<<9<<" "<<10;
       else puts("-1");
   }
   
   //system("pause");
   return 0;
}
