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
       int n;
       cin>>n;
       if(n==1) cout<<-1;
       else 
       {    cout<<2;
           for(int i=2;i<=n;i++) cout<<3;
       }
       cout<<endl;
   }
   //system("pause");
   return 0;
}
