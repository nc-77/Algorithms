#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
double a[maxn],b[maxn];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       double ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        b[1]=a[n];
        for(int i=2;i<=n;i++) b[i]=a[i-1];
        for(int i=1;i<=n;i++) ans+=1.0/max(a[i],b[i]);
        printf("%.2f\n",ans);
   }
   //system("pause");
   return 0;
}
