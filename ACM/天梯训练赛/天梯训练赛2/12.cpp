#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int fa[maxn],ma[maxn],flag;
char sex[maxn];
set<int>s;
void add(int x,int num)
{
	if(num>=5) return ;
	s.insert(x);
	if(fa[x]!=-1)add(fa[x],num+1);
	if(ma[x]!=-1)add(ma[x],num+1);
}
void dfs(int x)
{	
	if(s.find(x)!=s.end())
	{
		flag=0;
		return;
	}
	if(ma[x]!=-1)dfs(ma[x]);
	if(fa[x]!=-1)dfs(fa[x]);
}
int main()
{
	int n;
	cin>>n;
	memset(fa,-1,sizeof(fa));
	memset(ma,-1,sizeof(ma));
	for(int i=1;i<=n;i++)
	{	int id,fath,math;
		char sx;
		cin>>id>>sx>>fath>>math;
		fa[id]=fath;
		ma[id]=math;
		sex[id]=sx;
		sex[fath]='M';
		sex[math]='F';
	}
	int q;
	cin>>q;
	while(q--)
	{	flag=1;
		int x,y;
		cin>>x>>y;
		s.clear();
		if(sex[x]==sex[y]) cout<<"Never Mind"<<endl;
		else
		{	
			add(x,0);
			dfs(y);
			if(flag) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}
