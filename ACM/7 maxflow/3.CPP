#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define ll long long
#define debug(x) cout << #x << '=' << x << endl
#define set0(x) memset(x, 0, sizeof(x))
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf = 0x3f3f3f3f;
const int maxn = 2e3 + 10;
int n, m;
struct edge
{
	int to, cap, rev;
};
vector<edge> g[maxn];
int level[maxn];
int iter[maxn]; //当前弧
void add(int from, int to, int cap)
{
	g[from].push_back(edge{to,cap,(int)g[to].size()});
	g[to].push_back(edge{from, 0, (int)g[from].size() - 1});
}
void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while (!que.empty())
	{
		int v = que.front();
		que.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			edge &e = g[v][i];
			if (e.cap > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}
int dfs(int v, int t, int f)
{
	if (v == t)
		return f;
	for (int &i = iter[v]; i < g[v].size(); i++)
	{
		edge &e = g[v][i];
		if (e.cap > 0 && level[v] < level[e.to])
		{
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0)
			{	
				e.cap -= d;
				g[e.to][e.rev].cap += d;
				//debug(d);
				return d;
			}
			
		}
	}
	if(!f) level[v]=-1; 
	return 0;
}
int maxflow(int s, int t)
{
	int flow = 0;
	while (1)
	{
		bfs(s);
		
		if (level[t] < 0)
			return flow;
			
		set0(iter);
		int f;
		while (f = dfs(s, t, inf) > 0)
			flow += f;
	}
}
int main()
{
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		for(int i=0;i<=maxn;i++) g[i].clear();
		cin >> n >> m;
		int sump = 0;
		int maxx = 0;
		for (int i = 1; i <= n; i++)
		{
			int st, ed, p;
			scanf("%d%d%d",&p,&st,&ed);
			sump += p;
			add(0, i, p);
			maxx=max(maxx,ed+n);
			for(int j=n+st;j<=n+ed;j++)
			add(i,j,1);
		}
		for(int i=n+1;i<=maxx;i++)
		add(i,maxx+1,m);
		int ans = maxflow(0,maxx+1 );
		//debug(ans);
		if (ans >= sump)
			printf("Case %d: Yes\n\n", k);
		else
			printf("Case %d: No\n\n", k);
		
	}
	
	//system("pause");
	return 0;
}
