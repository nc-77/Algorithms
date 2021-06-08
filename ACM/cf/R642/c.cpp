#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],sum[maxn];
signed main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   a[1]=0;
   a[3]=8;
   for(int i=5;i<=5e5;i++)
   a[i]=a[i-2]+(i-1)/2*(i-1)*4;
   while(t--)
   {
       int n;
       cin>>n;
        cout<<a[n]<<endl;

       
   }
   //system("pause");
   return 0;
}
