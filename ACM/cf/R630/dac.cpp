#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int k;
   cin>>k;
   cout<<"3 4"<<endl;
   int x=1;
   while(x<=k)
   {
       x=x<<1;
   }
   int y=x-1;
   printf("%d %d %d 0\n",x+y,y,y);
    printf("%d 0 %d 0\n",x,y);
    printf("%d %d %d %d\n",x,x,x+y,k);
    
   //system("pause");
   return 0;
}
