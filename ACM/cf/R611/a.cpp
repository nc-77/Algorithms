#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int x,y;
       cin>>x>>y;
       int a=24-x;
       int b=60-y;
       cout<<b+(a-1)*60<<endl;
   }
   //system("pause");
   return 0;
}
