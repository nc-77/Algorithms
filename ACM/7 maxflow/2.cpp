#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e2+10;
int a[maxn][maxn],pre[maxn],flow[maxn];
int bfs(int s,int t)
{	set0(flow);
	memset(pre,-1,sizeof(pre));
	flow[s]=inf;
	queue<int>que;
	que.push(s);
	while(!que.empty())
	{
		int cur=que.front();
		que.pop();
		if(cur==t) break;
		for(int i=1;i<=t;i++)
		{
			if(cur!=i&&a[cur][i]>0&&pre[i]==-1)
			{
				pre[i]=cur;
				que.push(i);
				flow[i]=min(flow[cur],a[cur][i]);
			}
		}
	}
	if(pre[t]==-1) return -1;
	return flow[t];
}
int maxflow(int s,int t)
{
	int ans=0;
	while(1)
	{
		int flow=bfs(s,t);
		if(flow==-1) break;
		ans+=flow;
		int temp=t;
		while(temp!=s)
		{
			int p=pre[temp];
			a[p][temp]-=flow;
			a[temp][p]+=flow;
			temp=p;
		}
		//debug(ans);
	}
	return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {	set0(a);
    	int n,m;
    	cin>>n>>m;
    	while(m--)
    	{
    		int x,y,z;
    		cin>>x>>y>>z;
    		
    		a[x][y]+=z;
		}
		printf("Case %d: %d\n",i,maxflow(1,n));
	}
}

