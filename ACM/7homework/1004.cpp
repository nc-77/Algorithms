#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int w[maxn],v[maxn],f[maxn],q[maxn];
int main()
{
   int n;
   while(cin>>n&&n>=0)
   {
       
       int m=0;
    for(int i=1;i<=n;i++) cin>>v[i]>>q[i],m+=v[i]*q[i];
    set0(f);
    
    for(int i=1;i<=n;i++)
    	for(int j=m;j>=v[i];j--)
        {
            for(int k=1;k<=q[i]&&j>=v[i]*k;k++)
            f[j]=max(f[j],f[j-v[i]*k]+v[i]*k);
        }
    	
    	cout<<m-f[m/2]<<" "<<f[m/2]<<endl;
   }
   //system("pause");
   return 0;
}
