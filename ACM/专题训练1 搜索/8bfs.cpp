#include<bits/stdc++.h>
using namespace std;
int n,m,sy,sx,ex,ey,flag,num,vis[105][105];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};//об ср ио вС 
char maze[105][105];
struct node
{
	int x;
	int y;
	int turn;
}cur,nex;
void bfs()
{
	queue<node>que;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		if(cur.x==ex&&cur.y==ey&&cur.turn<=num)
		{
			flag=1;
			return;
		}
		if(cur.turn>num) return;
		for(int i=0;i<4;i++)
		{
			nex.x=cur.x+dx[i];
			nex.y=cur.y+dy[i];
			while(maze[nex.x][nex.y]=='.')
			{
				if(nex.x>0&&nex.x<=n&&nex.y>0&&nex.y<=m&&!vis[nex.x][nex.y])
				{
					vis[nex.x][nex.y]=1;
					nex.turn=cur.turn+1;
					que.push(nex);
					//cout<<nex.x<<" "<<nex.y<<" "<<nex.turn<<endl;
				}
				nex.x+=dx[i];
				nex.y+=dy[i];
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	 flag=0;
		
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				vis[i][j]=0;
				cin>>maze[i][j];
			}
		cin>>num>>sy>>sx>>ey>>ex;
		cur.x=sx,cur.y=sy,cur.turn=-1;
		vis[sx][sy]=1;
		//dfs(sx,sy,-1);
		bfs();
		if(flag) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
