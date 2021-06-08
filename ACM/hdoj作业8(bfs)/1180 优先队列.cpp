#include<bits/stdc++.h>
using namespace std;
int m,n,vis[25][25];
char mp[25][25];
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};//right left top bottom
struct node
{
	int x,y,step;
	friend bool operator <(node node1,node node2)
	{
		return node1.step>node2.step;
	}
}cur,nex;
bool judge(int i,int j)
{
	if(mp[i][j]=='*'||vis[i][j]||mp[i][j]=='|'||mp[i][j]=='-') return false;
	else if(i<1||i>m||j<1||j>n) return false;
	else return true;
}
void bfs()
{
	priority_queue<node>que;
	memset(vis,0,sizeof(vis));
	cur.step=0;
	que.push(cur);
	vis[cur.x][cur.y]=1;
	while(!que.empty())
	{
		cur=que.top();
		//cout<<cur.x<<" "<<cur.y<<endl;
		que.pop();
		if(mp[cur.x][cur.y]=='T')
		{
			cout<<cur.step<<endl;
			return;
		}
		for(int i=0;i<4;i++)
		{
			nex.x=cur.x+dx[i];
			nex.y=cur.y+dy[i];
			if(judge(nex.x,nex.y))
			{
				vis[nex.x][nex.y]=1;
				nex.step=cur.step+1;
				que.push(nex);
			}
			else if(i==0||i==1)
			{
					if((mp[nex.x][nex.y]=='-'&&cur.step%2==0)||(mp[nex.x][nex.y]=='|'&&cur.step%2==1))
				{
						nex.y=nex.y+1-2*i;
						if(judge(nex.x,nex.y))
						{
						vis[nex.x][nex.y]=1;
						nex.step=cur.step+1;
						que.push(nex);
						}
					
				}
				 else if((mp[nex.x][nex.y]=='-'&&cur.step%2==1)||(mp[nex.x][nex.y]=='|'&&cur.step%2==0))
				{
					nex.x=cur.x;
					nex.y=cur.y;
					nex.step=cur.step+1;
					vis[nex.x][nex.y]=1;
					que.push(nex);
				}
			}
			else if(i==2||i==3)
			{
					if((mp[nex.x][nex.y]=='|'&&cur.step%2==0)||(mp[nex.x][nex.y]=='-'&&cur.step%2==1))
				{
						nex.x=nex.x+2*i-5;
						if(judge(nex.x,nex.y))
						{
						vis[nex.x][nex.y]=1;
						nex.step=cur.step+1;
						que.push(nex);
						
						}	
				}
				else if((mp[nex.x][nex.y]=='|'&&cur.step%2==1)||(mp[nex.x][nex.y]=='-'&&cur.step%2==0))
				{
					nex.x=cur.x;
					nex.y=cur.y;
					nex.step=cur.step+1;
					vis[nex.x][nex.y]=1;
					que.push(nex);
				}
			}
			
		}
	}
}
int main()
{
	while(cin>>m>>n)
	{
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{	cin>>mp[i][j];
				if(mp[i][j]=='S')
				{
					cur.x=i;
					cur.y=j;
				}
			}
		bfs();	
	}
 } 
