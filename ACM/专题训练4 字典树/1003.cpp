#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+10;
int tree[maxn][15],tot=0,vis[maxn];
string st[10000+10];
void add(string s,int num)
{
	int root=0,id,len=s.size();
	for(int i=0;i<len;i++)
	{
		id=s[i]-'0';
		if(!tree[root][id]) tree[root][id]=++tot;
		root=tree[root][id];

	}
	vis[num]=root;
	//cout<<num<<" "<<root<<endl;
}

int main()
{	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		for(int i=0;i<num;i++)
		{
			cin>>st[i];
			add(st[i],i);
		}
			int flag=0;
			for(int i=0;i<num;i++)
			{	for(int j=0;j<10;j++)
				if(tree[vis[i]][j])
				{
					flag=1;
					//cout<<vis[i]<<" "<<j<<" "<<tree[vis[i]][j];
				}
				if(flag) break;
			}
			if(flag)  puts("NO");
			else  puts("YES");
			tot=0;
			memset(tree,0,sizeof(tree));
			memset(vis,0,sizeof(vis));
	}
	
}
