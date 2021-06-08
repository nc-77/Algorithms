#include <bits/stdc++.h>
#define ll long long
#define debug(x) cout << #x << '=' << x << endl
#define set0(x) memset(x, 0, sizeof(x))
using namespace std;
//#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 2e6 + 10;
string s[20];
int a[30][30], vis[20];
vector<char> g[30];
int n, m, flag;
bool check(char x)
{
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] >= 2)
            return false;
    }
    return true;
}
void dfs(int x, string ans)
{
    if (x == m + 1 && !flag)
    {
        if (ans.size() == m)
        {
            flag = 1;
            cout << ans << endl;
        }
        return;
    }
    if (x > m)
        return;

    for (int k = 0; k < g[x].size(); k++)
    {
        char t = g[x][k];
        // debug(x),debug(ans);
        int f = 1;
        for (int j = 1; j <= n; j++)
        {
            if (s[j][x] != t)
                vis[j]++;
            if (vis[j] >= 2)
            {
                f = 0;
            }
        }
        if (!f)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[j][x] != t)
                    vis[j]--;
            }
            continue;
        }
        else
        {
            dfs(x + 1, ans + t);
            for (int j = 1; j <= n; j++)
            {
                if (s[j][x] != t)
                    vis[j]--;
            }
        }
        if (flag)
            return;
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> m;
        flag = 0;
        for (int i = 1; i <= n; i++)
            cin >> s[i], s[i] = " " + s[i];
        set0(vis);
        for (int i = 1; i <= m; i++)
            g[i].clear();
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                g[i].push_back(s[j][i]);
            }
        dfs(1, "");
        if (!flag)
            cout << -1 << endl;
    }
    //system("pause");
    return 0;
}
