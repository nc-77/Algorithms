#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define PII pair<int,int>
using namespace std;
struct edge
{
	int to,cost;
};
vector<edge>g[1050];
int d[1050];
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
}
int main()
{
	int T,S,D,r1,r2,start,end;
	while(cin>>T>>S>>D)
	{	edge a;
		int ans=INF;
		for(int i=0;i<=1050;i++)
		g[i].clear();
		while(T--)
		{
			cin>>r1>>r2>>a.cost;
			a.to=r2;
			g[r1].push_back(a);
			a.to=r1;
			g[r2].push_back(a);
		}
		while(S--)
		{
			cin>>a.to;
			a.cost=0;
			g[0].push_back(a);
		}
		dijkstra(0);
//		for(int i=0;i<=10;i++)
//		cout<<i<<" "<<d[i]<<endl;
		while(D--)
		{
			cin>>end;
			ans=min(ans,d[end]);
		}
		cout<<ans<<endl;
	}		
}
