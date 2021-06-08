#include <bits/stdc++.h>
#define debug(x) cout << #x << '=' << x << endl
#define set0(x) memset(x, 0, sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e6 + 10;
ll a[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	int t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		ll sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		cout << min(sum, m) << endl;
	}
}
