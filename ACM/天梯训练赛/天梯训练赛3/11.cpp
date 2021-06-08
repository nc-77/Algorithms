#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>g[505];
int color[505];
int v,e,k;
set<int>s;
int main()
{
	cin>>v>>e>>k;
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int q;
	cin>>q;
	while(q--)
	{	int flag=1,num=0;
		memset(color,0,sizeof(color));
		s.clear();
		for(int i=1;i<=v;i++)
		{
			cin>>color[i];
			s.insert(color[i]);
		}
		if(s.size()!=k) flag=0; 
		for(int i=1;i<=v;i++)
		{
			for(int j=0;j<g[i].size();j++)
			{
				if(color[g[i][j]]==color[i])
				{	
					flag=0;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag) puts("Yes");
		else puts("No");
	}
}
