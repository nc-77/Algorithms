#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e3+10;
int v[maxn],w[maxn],m[maxn],f[maxn][maxn];
int main()
{
    freopen("in.txt","r",stdin);
    int n,M,W;
    cin>>n>>M>>W;
    for(int i=1;i<=n;i++) cin>>v[i]>>m[i]>>w[i];
    for(int i=1;i<=n;i++)
    	for(int j=M;j>=v[i];j--)
    		for(int k=W;k>=m[i];k--)
    	f[j][k]=max(f[j][k],f[j-v[i]][k-m[i]]+w[i]);
    	cout<<f[M][W]<<endl;
}

