#include<bits/stdc++.h>
using namespace std;
//int d[10000+1][10000+1],t[10000+1][10000+1];
vector<int>g[10000+1];
int lost[10000+1];
int main()
{
	int n,e;
	cin>>n>>e;
	while(e--)
	{
		int x,y;
		cin>>x>>y;
		//d[x][y]=d[y][x]=1;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int q;
	cin>>q;
	while(q--)
	{	//for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
			//t[i][j]=d[i][j];
			
		int flag=1;
		memset(lost,0,sizeof(lost));
		int k;
		cin>>k;
		while(k--)
		{
			int x;
			cin>>x;
			lost[x]=1;
		
		
		}
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//			{	if(i==j) continue;
//				if(t[i][j]==1)
//				{
//					flag=0;
//					break;
//				}
//			}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<g[i].size();j++)
			{
				if(!lost[i]&&!lost[g[i][j]])
				{
					flag=0;
					break;
				}
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
}
