#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e3+10;
int w[maxn],v[maxn],f[maxn],q[maxn];
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i]>>q[i];
    set0(f);
    for(int i=1;i<=n;i++)
    	for(int j=m;j>=v[i];j--)
        {
            for(int k=1;k<=min(q[i],j/v[i]);k++)
            f[j]=max(f[j],f[j-v[i]*k]+w[i]*k);
        }
    	
    	cout<<f[m]<<endl;
   }
   //system("pause");
   return 0;
}
