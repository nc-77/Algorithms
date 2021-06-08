#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int v[maxn],w[maxn],f[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
    for(int i=1;i<=n;i++)
    	for(int j=v[i];j<=m;j++)
    	f[j]=max(f[j],f[j-v[i]]+w[i]);
    	cout<<f[m]<<endl;
}

