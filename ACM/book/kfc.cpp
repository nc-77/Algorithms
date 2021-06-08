#include<bits/stdc++.h>
using namespace std;
const int MAX=1000+10;
char f[MAX][MAX];
struct pos
{
	int x;
	int y;
};
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dis[MAX][MAX],n,m,vis[MAX][MAX],k1[MAX][MAX],k2[MAX][MAX];
int bfs(pos start,int k[][MAX],int sumk)
{	 memset(dis,0,sizeof(dis));
	 memset(vis,0,sizeof(vis));
	 pos cur,nex;
	 queue<pos> que;
	 que.push(start);
	 while(!que.empty()&&sumk)
	 {	cur=que.front();que.pop();
	 	if(f[cur.x][cur.y]=='K')
	 	{
	 		k[cur.x][cur.y]=dis[cur.x][cur.y];
	 		//cout<<k[cur.x][cur.y]<<endl;
	 		sumk--;
		 }
	 	for(int i=0;i<4;i++)
	 	{
	 		nex.x=cur.x+dx[i];nex.y=cur.y+dy[i];
	 		if(f[nex.x][nex.y]!='#'&&nex.x>=0&&nex.x<n&&nex.y>=0&&nex.y<m&&!vis[nex.x][nex.y])
	 		{
	 			que.push(nex);
	 			vis[nex.x][nex.y]=1;
	 		    dis[nex.x][nex.y]=dis[cur.x][cur.y]+1;
			}
		 }
		 
	 }
	 return dis[cur.x][cur.y];
}
int main()
{
	
	while(cin>>n>>m)
	{	int min=1000010,ans=0,flag=0,sumk=0;
		pos begin1,begin2;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				scanf(" %c",&f[i][j]);
				if(f[i][j]=='S')
				{
					begin1.x=i;
					begin1.y=j;
				}
				else if(f[i][j]=='E')
				{
					begin2.x=i;
					begin2.y=j;
				}
				else if(f[i][j]=='K')
				sumk++;
			}
			memset(k1,0,sizeof(k1));
			memset(k2,0,sizeof(k2));
			bfs(begin1,k1,sumk);
			bfs(begin2,k2,sumk);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(k1[i][j]&&k2[i][j])
					{ 
						flag=1;
						ans=k1[i][j]+k2[i][j];
						if(ans<=min) min=ans;
					}
				}
			}
		if(flag)cout<<min<<endl;
		else cout<<"-1"<<endl;
	}
}
