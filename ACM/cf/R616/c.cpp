#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int a[5000],vis[5000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	memset(a,0,sizeof(a));
		int n,m,k,ans=0,maxx=0,minn=inf,w=0;
		cin>>n>>m>>k;
		int len=n-m+1;
		for(int i=0;i<n;i++)
		cin>>a[i];
		k=min(k,m-1);
		for(int i=0;i<=k;i++)
		{	maxx=0,minn=inf;
			 w=k-i;
			for(int j=i;j<=n-w-len;j++)
			{	
				maxx=0;
				
				maxx=max(a[j],a[j+len-1]);
				
				minn=min(minn,maxx);
				//cout<<minn<<endl;
				
			}
			//cout<<minn<<endl;
			ans=max(minn,ans);
		}
		if(m==1) 
		{
			ans=max(a[0],a[n-1]);
		 } 
		cout<<ans<<endl;
	}
}
