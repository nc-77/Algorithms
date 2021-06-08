#include <bits/stdc++.h>
#define INT 0x7fffffff
#define  cind(x) scanf("%d",&x)
#define cinc(x) scanf("%c",&x);while(ch==' '||ch=='\n')scanf("%c",&x);
#define kt  int t;scanf("%d",&t);while(t--)
#define mem0(x) memset(x,0,sizeof(x));
#define ll long long int
#define mem(x,y) memset(x,y,sizeof(x));
#define INT2 0x7ffffff
using namespace std;
map<int, int>mp, mp1;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int a[1000], b[1000], c[1000];
		int i, j;
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		int f = 0, f1 = 0;
		for (i = 0; i < n - 1; i++)
		{
			if (a[i] > a[i + 1])
			{
				f = 1;
				break;
			}
		}
		if (f == 0)
		{
			cout << "YES" << endl;
			continue;
		}
		for (i = 0; i < n - 1; i++)
		{
			if (b[i] != b[i + 1])
			{
				f1 = 1;
				break;
			}
		}
		if (f1 == 1)
		{
			cout << "YES" << endl;
		}
		else
			cout << "NO" << endl;

	}
}