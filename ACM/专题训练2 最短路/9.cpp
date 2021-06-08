#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define PII pair<int,int> 
using namespace std;
int V,E,last,d[1010];
struct edge
{
	int to,cost;
};
vector<edge>g[1010];
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
		if(d[v]<p.first) continue;//已经不是最短距离了就舍弃
		for(int i=0;i<g[v].size();i++)
		{
			edge e=g[v][i];
			if(d[e.to]>d[v]+e.cost)
			{
			   d[e.to]=d[v]+e.cost;
			   que.push(PII(d[e.to],e.to));//更新相邻顶点距离入队
			}
		}
	}
}
int main()
{	ios::sync_with_stdio(false);
	int r1,nums,s;
	edge a;
	while(cin>>V>>E>>last)
	{
		for(int i=1;i<=1010;i++)
		g[i].clear();
		while(E--)
		{	
			cin>>r1>>a.to>>a.cost;
			g[r1].push_back(a);
		}
		cin>>nums;
		while(nums--)
		{
			cin>>s;
			a.to=s;
			a.cost=0;
			g[V+1].push_back(a);
		}
		dijkstra(V+1);
		if(d[last]!=inf) cout<<d[last]<<endl;
		else cout<<"-1"<<endl;
	}
	
}
