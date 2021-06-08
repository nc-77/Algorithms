#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;
int d[maxn],a[maxn];
bool cmp(int a,int b){
    return a>b;
}
int main()
{
   //ios::sync_with_stdio(false);
   int n,m;
   cin>>n>>m;
   while(m--)
   {
       int l,r;
       cin>>l>>r;
       d[l]++;
       d[r+1]--;
   }
   for(int i=1;i<=n;i++)
   {
       a[i]=a[i-1]+d[i];
       //debug(a[i]);
   }
   sort(a+1,a+n+1,cmp);
   ll ans=0,now=n;
   for(int i=1;i<=n;i++)
   {
       ans+=a[i]*now;
       now--;
   }
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
