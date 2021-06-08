#include<bits/stdc++.h>
using namespace std;
int vis[100000+10],maxx=0;
vector<int>g[100000+10];
struct node
{
	int step;
	int pos;
}cur,nex;
void bfs(int s)
{	cur.pos=s;
	cur.step=0;
	queue<node>que;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		
		for(int i=0;i<g[cur.pos].size();i++)
		{
			nex.pos=g[cur.pos][i];
			nex.step=cur.step+1;
			que.push(nex);
			
		}
	}
	cout<<cur.pos<<endl;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int num;
			cin>>num;
			vis[num]=1;
			g[i].push_back(num);
		}
	}
	int st;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			st=i;
			break;
		}
	}
	
	bfs(st);
}
