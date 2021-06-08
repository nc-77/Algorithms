#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,sy,sx,ex,ey,flag,num,vis[105][105];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};//об ср ио вС 
char maze[105][105];
int turn[105][105];
const int maxn=0x3f3f3f3f;
void dfs(int x,int y,int dir)
{
	if(x==ex&&y==ey&&turn[x][y]<=num)
	{
		flag=1;
		return;
	}
	if(turn[x][y]>num) return;
	if(turn[x][y]==num&&x!=ex&&y!=ey) return;
	for(int i=0;i<4;i++)
	{	 
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(!vis[nx][ny]&&nx>=1&&nx<=n&&ny>=1&&ny<=m&&maze[nx][ny]=='.')
		{	
			
			if(turn[x][y]>turn[nx][ny]) continue;
			
			if(dir!=i&&dir!=-1)
			turn[nx][ny]=turn[x][y]+1;
			else
			turn[nx][ny]=turn[x][y];
			if(flag) return;
			
			vis[nx][ny]=1;
			dfs(nx,ny,i);
			vis[nx][ny]=0;
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
			cin>>maze[i][j];
			
		memset(vis,0,sizeof(vis));
		memset(turn,0x3f,sizeof(turn));
		cin>>num>>sy>>sx>>ey>>ex;
		vis[sx][sy]=1;
		turn[sx][sy]=0;
		dfs(sx,sy,-1);
		if(flag) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
} 
