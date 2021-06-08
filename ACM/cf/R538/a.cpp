#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   int x,y,z,a,b,c;
   cin>>x>>y>>z>>a>>b>>c;
   int flag=1;
   if(a<x) flag=0;
   a=a-x;
   if(a+b<y) flag=0;
    int sum=(a+b)-y;
    if(sum+c<z) flag=0;
    if(flag) puts("YES");
    else puts("NO");
   //system("pause");
   return 0;
}
