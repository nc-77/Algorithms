#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn],n;
bool judge(int x)
{
    for(int i=1;i<=n;i++) 
    {
        b[i]=a[i]+x/n;
        if(i<=x%n) b[i]++;
    }
    int mi=0,k;
    sort(b+1,b+n+1);
    k=b[n/2+1];
     for(int i=1;i<=n;i++)
     mi+=abs(k-b[i]);
     if(x>=mi) return true;
     else return false;
}
signed main()
{
   //ios::sync_with_stdio(false);
   
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   int l=0,r=1e14+10;
   while(r-l>1)
   {
       int mid=(l+r)/2;
       //debug(l),debug(r),debug(mid);
       if(judge(mid)) r=mid;
       else l=mid;
   }
   cout<<r<<endl;
   //system("pause");
   return 0;
}
