#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;

int sum[maxn],a[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int cnt;
   for(int i=1;;i++)
   {
      sum[i]=sum[i-1]+2*i+i-1;
      if(sum[i]>1e9) 
      {
         cnt=i;
        break;}
   }
   int t;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
      int ans=0;
      while(1)
      {
         int pos=upper_bound(sum+1,sum+cnt+1,n)-sum;
         //debug(pos);
         if(pos==1) break;
         ans++;
         n-=sum[pos-1];
         //debug(n);
        
      }
      cout<<ans<<endl;
      
   }
   //system("pause");
   return 0;
}
