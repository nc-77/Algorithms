#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn];
int main()
{
   int t;
   cin>>t;
   a[2]=1,a[3]=2;
        for(int i=4;i<=50;i++) a[i]=a[i-1]+a[i-2];
   while(t--)
   {
       int n,m;
            cin>>n>>m;
            cout<<a[m-n+1]<<endl;
        
   }
   //system("pause");
   return 0;
}
