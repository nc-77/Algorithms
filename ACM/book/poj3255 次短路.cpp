#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define PII pair<int,int>
using namespace std;
int N,R,dis1[5050],dis2[5050];
struct edge
{
	int to,cost;
};
vector<edge>g[5050];
void dijkstra(int s)
{
	priority_queue<PII,vector<PII>,greater<PII> >que;
	memset(dis1,0x3f,sizeof(dis1));
	memset(dis2,0x3f,sizeof(dis2));
	dis1[s]=0;
	que.push(PII(0,s));
	while(!que.empty())
	{
		PII p=que.top();
		que.pop();
		int v=p.second,d=p.first;
		if(d>dis2[v]) continue;
		for(int i=0;i<g[v].size();i++)
		{
			edge e=g[v][i];
			int d2=d+e.cost;
			if(dis1[e.to]>dis1[v]+e.cost)
			{
				swap(dis1[e.to],d2);
				que.push(PII(dis1[e.to],e.to));
				//cout<<e.to<<" "<<dis1[e.to]<<" "<<dis2[e.to]<<endl; 
			}
			if(d2>dis1[e.to]&&d2<dis2[e.to])
			{
				dis2[e.to]=d2;
				que.push(PII(dis2[e.to],e.to));
				//cout<<e.to<<" "<<dis1[e.to]<<" "<<dis2[e.to]<<endl;
			}
		}
		//printf("\n");
	}
	cout<<dis2[N]<<endl;
}
int main()
{
	cin>>N>>R;
	edge a;
	int u,v,cost;
	for(int i=0;i<R;i++)
	{
		scanf("%d%d%d",&u,&v,&cost);
            a.to=v;
			a.cost=cost;
            g[u].push_back(a);
            a.to=u;
            g[v].push_back(a);
	}
	dijkstra(1);
} 
