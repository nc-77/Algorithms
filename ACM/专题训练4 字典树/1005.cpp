#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int tree[maxn][30],tot=0;

void add(string s)
{
	int root=0,id,len=s.size();
	for(int i=0;i<len;i++)
	{
		id=s[i]-'a';
		if(!tree[root][id]) tree[root][id]=++tot;
		root=tree[root][id];
	}

}
int main()
{	ios::sync_with_stdio(false);
	int n;
	string s;
	while(cin>>n)
	{	memset(tree,0,sizeof(tree));
		int maxx=0,ans=n,len;
		tot=0;
		while(n--)
		{	
			cin>>s;
			add(s);
			len=s.size();
			maxx=max(maxx,len);
		}
		ans+=tot+tot-maxx;
		cout<<ans<<endl;
	}
}
