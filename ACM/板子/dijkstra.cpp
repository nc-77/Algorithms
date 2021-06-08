#include<bits/stdc++.h>
#define PII pair<int,int> 
#define MAX_V 100
using namespace std;
const int inf=0x3f3f3f3f;
struct edge{int to,cost;};
vector<edge>G[MAX_V];
int d[MAX_V];
void dirjkstra(int s)
{	priority_queue<PII,vector<PII>,greater<PII> >que;
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	que.push(PII(0,s));
	while(!que.empty())
	{
		PII p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first) continue;
		for(int i=0;i<G[v].size();i++)
		{
			edge e=G[v][i];
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
	int n,m,s;
	cin>>n>>m>>s;
	while(m--)
	{
		int x,y,cost;
		cin>>x>>y>>cost;
		G[x].push_back({y,cost});
	}
	dirjkstra(s);
	for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" "<<endl;
	}
}

