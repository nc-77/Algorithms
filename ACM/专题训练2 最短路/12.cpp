#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,d[105],r[105][105],cost[105],vis[105];
int ans[10010];
void dijkstra(int s)
{	
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[s]=0;
	for(int i=0;i<=n;i++)
	{	int MIN=inf;
		int p;
		for(int j=0;j<=n;j++)
		{	
			if(!vis[j]&&d[j]<MIN)
			{
				p=j;
				MIN=d[j];
			}
		}//从尚未使用过的顶点中选择一个距离最小的点
		vis[p]=1;
		if(MIN==inf) break;	//所有顶点都已经用过
		for(int j=0;j<=n;j++)
		d[j]=min(d[j],d[p]+r[p][j]);//更新相邻顶点的最短距离	
	}
}
int main()
{	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	
	while(t--)
	{	memset(r,0x3f,sizeof(r));
		for(int i=0;i<=n;++i)r[i][i]=0;
		int sum1=0,sum2=0;
		cin>>n>>m;
		while(m--)
		{
			int st,ed,dis;
			cin>>st>>ed>>dis;
			r[st][ed]=r[ed][st]=min(r[st][ed],dis);
		}
		for(int i=1;i<=n;i++)
		{
			cin>>cost[i];
			sum1+=cost[i];
		}
		dijkstra(0);
		for(int i=1;i<=n;i++)
		{
			if(d[i]!=inf)
			sum2+=cost[i];
			
		}
		if(sum2<=sum1/2)
		{
			cout<<"impossible"<<endl;
			continue;
		}
		int sumd=0,v;
		if(sum1%2==0) v=sum1/2-1;
		else v=sum1/2;
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
		{
			if(d[i]==inf) continue;
			sumd+=d[i];
			for(int j=v;j>=cost[i];j--)
			{
				ans[j]=max(ans[j],ans[j-cost[i]]+d[i]);
			}
		}
		
		cout<<sumd-ans[v]<<endl;
	}
}
