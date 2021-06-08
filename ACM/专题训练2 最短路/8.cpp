#include<bits/stdc++.h>
#define PII pair<int,int> 
using namespace std;
struct edge
{
	int to,cost;
};
vector<edge>g[105];
int d[105];
int n,m,u,v,c;
void dijkstra(int s)
{
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> >que;
	que.push(PII(0,s));
	while(!que.empty())
	{
		PII p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first) continue;
		for(int i=0;i<g[v].size();i++)
		{
			edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
				d[e.to]=d[v]+e.cost;
				que.push(PII(d[e.to],e.to));
			}
		}
	}
	cout<<d[n]<<endl;
}
int main()
{
	
	edge a;
	while(cin>>n>>m&&!(n==0&&m==0))
	{	for(int i=0;i<=n;i++)
		g[i].clear();
		for(int i=0;i<m;i++)
		{
			cin>>u>>v>>c;
			a.cost=c;
			a.to=v;
			g[u].push_back(a);
			a.to=u;
			g[v].push_back(a);
			
		}
		dijkstra(1);
	}
}
