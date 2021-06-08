#include<bits/stdc++.h>
using namespace std;
int n,m,vis[205][205];
char a[205][205];
int dx[]={-1,1,0,0},dy[]={0,0,1,-1};
struct pos
{
	int x,y;
	int step;
	friend bool operator <(pos t1,pos t2)
	{
		return t1.step>t2.step;//step小的在前 
	}
}cur,nex;
bool pd()
{
	if(nex.x<=n-1&&nex.x>=0&&nex.y>=0&&nex.y<=m-1&&a[nex.x][nex.y]!='#'&&!vis[nex.x][nex.y])
	return true;
	return false;
}
void bfs()
{
	cur.step=0;
	priority_queue<pos>que;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.top();
		que.pop();
		if(a[cur.x][cur.y]=='r')
		{
			cout<<cur.step<<endl;
			return;
		}
		for(int i=0;i<4;i++)
		{
			nex.x=cur.x+dx[i];
			nex.y=cur.y+dy[i];
			//printf("%d %d\n",nex.x,nex.y);
			if(pd())
			{	vis[nex.x][nex.y]=1;
				//printf("%d %d\n",nex.x,nex.y);
				if(a[nex.x][nex.y]=='x')
				{
					nex.step=cur.step+2;
				}
				else nex.step=cur.step+1;
				que.push(nex);
			}
			
		}
	}
cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{	
		//printf("here\n");
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{	vis[i][j]=0;
				//printf("here\n");
				scanf(" %c",&a[i][j]);
				if(a[i][j]=='a')
				{
					cur.x=i;
					cur.y=j;
					vis[i][j]=1;
				}
			}
		
		bfs();
	}
return 0;
}
