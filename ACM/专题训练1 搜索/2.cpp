#include<bits/stdc++.h>
using namespace std;
int n,m,maze[1010][1010],vis[1010][1010],x1,y1,x2,y2;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
struct node
{
	int x,y,step;
}cur,nex;
//bool judge(int x,int y)
//{        
//	if(x>0&&x<=n&&y>0&&y<=m&&vis[x][y]==0&&maze[x][y]==0)
//	return true;
//	else return false;
//}
void bfs()
{	//cout<<"here"<<endl;
	queue<node>que;
	memset(vis,0,sizeof(vis));
	vis[x1][y1]=1;
	cur.x=x1;
	cur.y=y1;
	cur.step=0;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		if(cur.step>3)
		{
			puts("NO");
			return;
		}
		for(int i=0;i<4;i++)
		{	
			nex.x=cur.x+dx[i];
			nex.y=cur.y+dy[i];
			
			while(vis[nex.x][nex.y]==0&&maze[nex.x][nex.y]==0)
			{	nex.step=cur.step+1;
				que.push(nex);
				//cout<<nex.x<<" "<<nex.y<<" "<<nex.step<<endl;
				if(nex.x==x2 && nex.y==y2)
                    {
                        if(nex.step<=3)
                            printf("YES\n");
                        else
                            printf("NO\n");
						return;
                    }
				vis[nex.x][nex.y]=1;
				nex.x+=dx[i];
				nex.y+=dy[i];
				
			}
		}
	}

}
int main()
{
	while(cin>>n>>m&&!(n==0&&m==0))
	{	memset(maze,-1,sizeof(maze));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
		scanf("%d",&maze[i][j]);
		int q;
		cin>>q;
		while(q--)
		{	
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			if(maze[x1][y1]!=maze[x2][y2]||maze[x1][y1]==0||maze[x2][y2]==0)
			puts("NO");
			
			else 
			{	int t=maze[x2][y2];
				maze[x2][y2]=0;
				bfs();
				maze[x2][y2]=t;
			}
		}	  
	}
 } 
