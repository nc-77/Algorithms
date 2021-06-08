#include<bits/stdc++.h>
#define PII pair<int,int>
#define inf 0x3f3f3f3f
using namespace std;
struct edge
{
	int to,cost;
};
vector<edge>g[5000]; 
int n,m;
int d[5000];
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
{	
	char ch;
	while(~scanf("%d%d",&n,&m)&&!(n==0&&m==0))
	{	edge a;
		int last=(n+1)*(m+1);
		//cout<<n<<" "<<m<<" "<<v<<endl;
		for(int i=0;i<=last;i++)
		g[i].clear();
		for(int i=1;i<=2*n+1;i++)
		{	if(i%2==1)
			{
				for(int j=0;j<m;j++)
				{	int bi=(i+1)/2*(m+1)-m+j;
					int ei=bi+1;
					scanf("%d %c",&a.cost,&ch);
					if(a.cost==0) continue;
					a.cost=2520/a.cost;
					if(ch=='*')
					{
						a.to=bi;
						g[ei].push_back(a);
						a.to=ei;
						g[bi].push_back(a);
					}
					else if(ch=='<')
					{
						a.to=bi;
						g[ei].push_back(a);
					}
					else if(ch=='>')
					{
						a.to=ei;
						g[bi].push_back(a);
					}
				}
			}
			else
			{
				for(int j=0;j<=m;j++)
				{
					int si=i/2*(m+1)-m+j;
					int di=si+m+1;
					scanf("%d %c",&a.cost,&ch);
					if(a.cost==0) continue;
					a.cost=2520/a.cost;
					if(ch=='*')
					{
						a.to=di;
						g[si].push_back(a);
						a.to=si;
						g[di].push_back(a);
					}
					else if(ch=='v')
					{
						a.to=di;
						g[si].push_back(a);
					}
					else if(ch=='^')
					{
						a.to=si;
						g[di].push_back(a);
					}
				}
			}
		}	
		dirjkstra(1);
//		for(int i=1;i<=9;i++)
//		cout<<d[i]<<endl;
//		cout<<v<<endl;
		 if(d[last]==inf) printf("Holiday\n");
        else printf("%d blips\n",d[last]);
	}
	
} 
