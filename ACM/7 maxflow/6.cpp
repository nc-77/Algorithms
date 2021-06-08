#include <bits/stdc++.h>
#define ll long long
#define debug(x) cout << #x << '=' << x << endl
#define set0(x) memset(x, 0, sizeof(x))
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e3 + 10;
int a[maxn][maxn];
struct edge
{
    int to, cap, rev;
};
vector<edge> g[maxn];
int level[maxn];
int iter[maxn]; //当前弧
void add(int from, int to, int cap)
{
    g[from].push_back(edge{to, cap, (int)g[to].size()});
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
        while (f=dfs(s, t, inf))
        flow += f;
    }
    return flow;
}
int main()
{
    int n;
    while (cin >> n)
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j], sum += a[i][j];
        for (int i = 0; i <= 20*20+10; i++)
            g[i].clear();
        int t = n * n + 1;
        for (int i = 1; i <= n * n; i++)
        {
            int y = (i + n - 1) % n + 1;
            int x = (i - y) / n + 1;
            if ((x+y)% 2 == 1)
            {   
                add(0, i, a[x][y]);
                if (y != 1)
                    add(i, i - 1, inf);
                if (y != n)
                    add(i, i + 1, inf);
                if (x != 1)
                    add(i, i - n, inf);
                if (x != n)
                    add(i, i + n, inf);
            }

            else
                add(i, t, a[x][y]);
        }

        int  ans = maxflow(0, t);
        cout << sum - ans << endl;
    }
    //system("pause");
    return 0;
}
