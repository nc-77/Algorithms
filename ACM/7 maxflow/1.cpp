#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=200+10;
int a[maxn][maxn],pre[maxn],flow[maxn];
int n,m;
int bfs(int s,int t)
{	set0(flow);
	flow[s]=inf;
	queue<int>que;
	que.push(s);
	memset(pre,-1,sizeof(pre));
	while(!que.empty())
	{
		int cur=que.front();
		que.pop();
		if(cur==t) break;
		for(int i=1;i<=t;i++)
		{
			if(a[cur][i]>0&&pre[i]==-1)
			{
				que.push(i);
				pre[i]=cur;
				flow[i]=min(flow[cur],a[cur][i]);
			}
		}
	}
	if(pre[t]==-1) return -1;
	return flow[t];
	
}
int  maxflow(int s,int t)
{
	int ans=0,flow;
	while(1)
	{
		flow=bfs(s,t);
		if(flow==-1) break;
		ans+=flow;
		int tt=t;
		while(tt!=s)
		{	//cout<<tt<<endl;
			a[pre[tt]][tt]-=flow;
			a[tt][pre[tt]]+=flow;
			tt=pre[tt];
		}
		//debug(ans);
	}
	return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(cin>>n>>m)
    {	set0(a);
    	while(n--)
    	{
    		int x,y,z;
    		cin>>x>>y>>z;
    		a[x][y]+=z;
    		
		}
		cout<<maxflow(1,m)<<endl;
	}
}

