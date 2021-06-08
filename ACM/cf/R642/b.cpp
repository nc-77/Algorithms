#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn];
bool cmp(int x,int y){
    return x>y;
}
signed main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n,k;
       cin>>n>>k;
       for(int i=1;i<=n;i++) cin>>a[i];
       for(int i=1;i<=n;i++) cin>>b[i];
       sort(a+1,a+n+1);
       sort(b+1,b+n+1,cmp);
       int i=1,j=1;
       int ans=0;
       while(k--)
       {
           if(a[i]<b[j]) {
               ans+=b[j];
               i++;
               j++;
           } 
           else break;
       }
       for(;i<=n;i++)
       {
           ans+=a[i];
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
