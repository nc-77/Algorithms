#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
const int mod=1e9+7;
ll v[maxn],w[maxn],f[maxn],t[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    t[0]=1;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>v[i]>>w[i],f[i]=-inf;
    for(int i=1;i<=n;i++)
    	for(int j=m;j>=v[i];j--)
    	{	
    		int g=max(f[j],f[j-v[i]]+w[i]);
    		int s=0;
    		if(g==f[j]) s+=t[j]%mod;
    		if(g==f[j-v[i]]+w[i]) s+=t[j-v[i]]%mod;
    		t[j]=s%mod;
    		f[j]=g;
		}
	ll maxx=0;
	for(int i=0;i<=m;i++) maxx=max(maxx,f[i]);
	ll res=0;
	for(int i=0;i<=m;i++)
	{
		if(f[i]==maxx)
		res+=t[i]%mod;
	}
	cout<<res%mod<<endl;-
}
