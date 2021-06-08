#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node
{
	int id;
	double bs;
}fs[100000+10];
vector<int>g[100000+10];
int b[100000+10];
map<int,int>mp;
struct p
{
	int step;
	int id;
}cur,nex;
void bfs()
{
	cur.id=0;
	cur.step=0;
	queue<p>que;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		if(mp[cur.id]) b[cur.id]=cur.step;
		//cout<<cur.id<<" "<<cur.step<<endl;
		for(int i=0;i<g[cur.id].size();i++)
		{
			nex.id=g[cur.id][i];
			nex.step=cur.step+1;
			que.push(nex);
		}
	}
}
int main()
{
	int n;
	double z,r;
	cin>>n>>z>>r;
	int cnt=0;
	for(int i=0;i<n;i++)
	{	
		int x;
		int k;
		cin>>k;
		if(k==0)  
		{
			fs[cnt].id=i;
			cin>>fs[cnt].bs;
			cnt++;
			mp[i]=1;
		}
		else
		{
			while(k--)
			{
				cin>>x;
				g[i].push_back(x);
			}
		}
	}
	bfs();
	double ans=0;
	r=1-r/100;
	for(int i=0;i<cnt;i++)
	{	//cout<<fs[i].id<<" "<<fs[i].bs<<" "<<b[fs[i].id]<<endl;
		ans+=z*pow(r,b[fs[i].id])*fs[i].bs;
	}
	printf("%d",(int)ans);
}
