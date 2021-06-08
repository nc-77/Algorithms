#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
double a[maxn];
int main()
{
   int n,m;
   cin>>n>>m;
   double sum=0;
   for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    sum=sum/(4.0*m);
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=sum) cnt++;
    }
    if(cnt>=m) puts("Yes");
    else puts("No");
   //system("pause");
   return 0;
}
