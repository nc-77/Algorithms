#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int v[maxn],w[maxn],f[maxn];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {    set0(f);
       int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++)
    	for(int j=m;j>=v[i];j--)
    	f[j]=max(f[j],f[j-v[i]]+w[i]);
    	cout<<f[m]<<endl;
   }
   //system("pause");
   return 0;
}
