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
    freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) 
	{	int s;
		cin>>s;
		for(int j=1;j<=s;j++)
		cin>>v[j]>>w[j];
		for(int j=m;j>=0;j--)
		{
			for(int k=1;k<=s;k++)
			{	if(j>=v[k])
				f[j]=max(f[j],f[j-v[k]]+w[k]);
			}
		}
	}
    
    	cout<<f[m]<<endl;
}

