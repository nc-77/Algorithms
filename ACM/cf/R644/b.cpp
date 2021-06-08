#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
int main()
{
   //ios::sync_with_stdio(false);
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       for(int i=1;i<=n;i++) cin>>a[i];
       sort(a+1,a+n+1);
       int ans=a[2]-a[1];
       for(int i=2;i<=n;i++)
       ans=min(ans,a[i]-a[i-1]);
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
