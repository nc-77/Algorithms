#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		stack<int>g;
		ll ans=0;
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(')
			g.push(i);
			if(s[i]==')')
			{
				if(g.empty()) ans++;
				else g.pop();
			}
		}
		cout<<ans+g.size()<<endl;
	}
}

