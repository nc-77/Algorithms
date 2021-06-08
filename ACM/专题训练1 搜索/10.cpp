#include<bits/stdc++.h>
using namespace std;
int n,m,vis[25][25][1100],t;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};//ÓÒÏÂ×óÉÏ
char maze[25][25];
struct node
{
	int x,y,step,key;
}cur,nex;
bool judge(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m&&maze[x][y]!='*')
	return true;
	return false;
}
void bfs()
{	//cout<<"here"<<endl;
	queue<node>que;
	cur.step=0;
	cur.key=0;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		//cout<<cur.step<<endl;
		if(maze[cur.x][cur.y]=='^'&&cur.step<t)
		{
			cout<<cur.step<<endl;
			return;
		}
		if(cur.step>=t)
		{
			puts("-1");
			return;
		}
		for(int i=0;i<4;i++)
		{
			 nex.x=cur.x+dx[i];
			 nex.y=cur.y+dy[i];
			 nex.key=cur.key;
			 if(!judge(nex.x,nex.y)||vis[nex.x][nex.y][nex.key]) 
			 continue;
			 if(maze[nex.x][nex.y]>='A'&&maze[nex.x][nex.y]<='J')
			 {
			 	if(nex.key&(1<<(maze[nex.x][nex.y]-'A')))
			 	{
			 		vis[nex.x][nex.y][nex.key]=1;
					 nex.step=cur.step+1;
					 que.push(nex);	
					 //cout<<nex.x<<" "<<nex.y<<" "<<vis[nex.x][nex.y][i]<<" "<<nex.step<<endl;
				} 
			 }
			 else 
			 {
			 	if(maze[nex.x][nex.y]>='a'&&maze[nex.x][nex.y]<='j')
			 	nex.key=nex.key|(1<<(maze[nex.x][nex.y]-'a'));
			 	vis[nex.x][nex.y][nex.key]=1;
				nex.step=cur.step+1;
				que.push(nex);
				//cout<<nex.x<<" "<<nex.y<<" "<<vis[nex.x][nex.y][i]<<" "<<nex.step<<endl;
			 }
		}
	
	}
puts("-1");
}
int main()
{
	while(cin>>n>>m>>t)
	{
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>maze[i][j];
				if(maze[i][j]=='@')
				{
					cur.x=i;
					cur.y=j;
				}
			}
		
		memset(vis,0,sizeof(vis));
		bfs();
	}
} 
