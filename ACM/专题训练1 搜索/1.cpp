#include<bits/stdc++.h>
using namespace std;
int m,n,maze[10][10],vis[10][10];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
struct node
{
	int x,y,step,num;
}cur,nex;
bool judge(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<n&&maze[x][y]==1)
	return true;
	return false;
}
void bfs()
{
	queue<node>que;
	//memset(vis,0,sizeof(vis));
	cur.step=0,cur.num=6;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		for(int i=0;i<4;i++)
		{
			nex.x=cur.x+dx[i];
			nex.y=cur.y+dy[i];
			if(maze[nex.x][nex.y]==3&&cur.num>1)
			{
				cout<<cur.step+1<<endl;
				return;
			}
			else if(judge(nex.x,nex.y)&&cur.num>1)
			{	
				//vis[nex.x][nex.y]=1;
				nex.num=cur.num-1;
				nex.step=cur.step+1;
				que.push(nex);
				//cout<<"1"<<nex.x<<" "<<nex.y<<" "<<nex.step<<" "<<nex.num<<endl;
			}
			else if(maze[nex.x][nex.y]==4&&cur.num>1)
			{
				//vis[nex.x][nex.y]=1;
				maze[nex.x][nex.y]=0;
				nex.num=6;
				nex.step=cur.step+1;
				que.push(nex);
				//cout<<"4"<<nex.x<<" "<<nex.y<<" "<<nex.step<<" "<<nex.num<<endl;
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
	{	cin>>m>>n;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>maze[i][j];
				if(maze[i][j]==2)
				{
					cur.x=i;
					cur.y=j;
				}
			}
		bfs();
	}
 } 
