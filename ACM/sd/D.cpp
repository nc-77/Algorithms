#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int n;
   cin>>n;
   if(n==1)
   {
       cout<<1<<"\n"<<1<<endl;
       return 0;
   }
   if(n==2)
   {
       cout<<2<<endl;
       cout<<0<<"\n"<<11<<endl;
       return 0;
   }
   cout<<n-1<<endl;
   for(int i=1;i<=n-1;i++)
   {
       cout<<0;
       for(int j=1;j<=i-1;j++)
       cout<<1;
       cout<<0<<endl;
   }
   //system("pause");
   return 0;
}
