#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[100];
int main()
{
   a[1]=0,a[2]=6;
   for(int i=3;i<=50;i++) a[i]=a[i-1]+2*a[i-2];
   a[1]=3;
   int n;
    while(cin>>n) cout<<a[n]<<endl;
   //system("pause");
   return 0;
}
