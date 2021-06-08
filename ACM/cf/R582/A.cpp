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
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   int cnt=0;
   for(int i=1;i<=n;i++)
   {
       if(a[i]%2) cnt++;
   }
   cout<<min(cnt,n-cnt)<<endl;
   //system("pause");
   return 0;
}
