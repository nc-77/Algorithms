#include<bits/stdc++.h>
using namespace std;
int par[100000+10];
int b[100000+10],c[100000+10];
int dfs(int x)
{
	if(x==-1) return 0;
	if(b[x]) return b[x];
	return b[x]=dfs(par[x])+1;

}
int main()
{
	int n,st,maxx=0,t=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		par[i]=x;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=dfs(i);
			//cout<<i<<" "<<b[i]<<endl;
		}
		maxx=max(b[i],maxx);
	}
	cout<<maxx<<endl;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(b[i]==maxx){
			c[cnt++]=i;
		}
	}
	for(int i=0;i<cnt;i++)
	{
		if(i!=cnt-1){
			cout<<c[i]<<" ";
		}
		else{
			cout<<c[i]<<endl;
		}
	}
	
}
