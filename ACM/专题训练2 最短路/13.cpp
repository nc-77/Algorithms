#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,vis[1050];
struct node1
{
	int dis;
	int p;
}d[1050];
struct node2
{
	int dis,p;
}r[1050][1050];
void dijkstra(int s)
{
	for(int i=1;i<=n;i++)
	{
		d[i].dis=inf;
		d[i].p=0;
	}
	d[s].dis=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{	int MIN=inf;
		int p;
		for(int j=1;j<=n;j++)
		{	
			if(!vis[j]&&d[j].dis<MIN)
			{
				p=j;
				MIN=d[j].dis;
			}
		}//从尚未使用过的顶点中选择一个距离最小的点
		vis[p]=1;
		if(MIN==inf) break;	//所有顶点都已经用过
		for(int j=1;j<=n;j++)
		{
			if(d[j].dis>d[p].dis+r[p][j].dis)
			{
				d[j].dis=d[p].dis+r[p][j].dis;
				d[j].p=d[p].p+r[p][j].p;
			}
			else if(d[j].dis==d[p].dis+r[p][j].dis)
			 {
			 	d[j].p=min(d[j].p,d[p].p+r[p][j].p);
			}                                     
			                                      
		}

	}
	
}
int main()
{	ios::sync_with_stdio(false);
	while(cin>>n>>m&&!(n==0&&m==0))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(i==j) r[i][j].dis=0;
				else r[i][j].dis=inf;
			}
		while(m--)
		{
			
			int a,b,d1,p1;
			cin>>a>>b>>d1>>p1;
			if(r[a][b].dis>d1)
			{
				r[a][b].dis=r[b][a].dis=d1;
				r[a][b].p=r[b][a].p=p1;
			}
			else if(r[a][b].dis==d1&&r[a][b].p>p1)
			r[a][b].p=r[b][a].p=p1;
			
		}
			int s1,e1;
			cin>>s1>>e1;
			dijkstra(s1);
			cout<<d[e1].dis<<" "<<d[e1].p<<endl;
	}
}
