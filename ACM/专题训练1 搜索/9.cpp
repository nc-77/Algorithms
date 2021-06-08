#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy,maze[10][10],visd[10][10],vis[10][10][5],flag;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};//ÓÒÏÂ×óÉÏ 
int fx[]={0,-1,0,1},fy[]={-1,0,1,0};
struct node
{
	int x,y,step;
	int gx,gy;
}cur,nex;
bool judge(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m&&maze[x][y]!=1&&!(x==cur.x&&y==cur.y))
	return true;
	return false;
}
void dfs(int x,int y,int ex,int ey)
{	if(x==ex&&y==ey)
	{
		flag=1;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(judge(nx,ny)&&!visd[nx][ny])
		{
			visd[nx][ny]=1;
			dfs(nx,ny,ex,ey);
			if(flag)
			return;
			visd[nx][ny]=0;
		}
		
	}
}
void bfs()
{
	queue<node>que;
	cur.step=0;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		if(maze[cur.x][cur.y]==3)
		{
			cout<<cur.step<<endl;
			return;
		}
		for(int i=0;i<4;i++)
		{
			 nex.x=cur.x+dx[i];
			 nex.y=cur.y+dy[i];
			 nex.gx=cur.x+fx[i];
			 nex.gy=cur.y+fy[i];
			if(!judge(nex.x,nex.y)||vis[nex.x][nex.y][i]) continue;
			if(!judge(nex.gx,nex.gy)) continue;
			flag=0;
			memset(visd,0,sizeof(visd));
			visd[cur.gx][cur.gy]=1;
			dfs(cur.gx,cur.gy,nex.gx,nex.gy);
			if(flag)
			{	vis[nex.x][nex.y][i]=1;
				nex.step=cur.step+1;
				//cout<<nex.x<<" "<<nex.y<<" "<<nex.step<<endl;
				que.push(nex);
			}
		}
	}
puts("-1");
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>maze[i][j];
				if(maze[i][j]==4)
				{
					cur.gx=i;
					cur.gy=j;
				}
				if(maze[i][j]==2)
				{
					sx=i;
					sx=j;
					cur.x=i;
					cur.y=j;
				}
			}
		memset(vis,0,sizeof(vis));
		bfs();
	}
}
