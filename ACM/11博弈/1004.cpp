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
   int n;
   while(cin>>n&&n)
   {
       int sum=0;
       for(int i=1;i<=n;i++) cin>>a[i],sum^=a[i];
       int ans=0;
       for(int i=1;i<=n;i++)
       {
           int res=sum^a[i];
           if(a[i]>res) ans++;
       }
       cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
