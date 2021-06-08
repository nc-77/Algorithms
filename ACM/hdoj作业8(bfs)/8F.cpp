#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int cube[55][55][55],vis[55][55][55];
int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};
struct pos
{
	int x,y,z;
	int step;
}cur,nex;
int  bfs()
{
	cur.x=cur.y=cur.z=cur.step=0;
	queue<pos>que;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		if(cur.x==a-1&&cur.y==b-1&&cur.z==c-1)
		{	return cur.step;
		}
		//printf("a%db%dc%d",a,b,c);
		for(int i=0;i<6;i++)
		{
			nex.x=cur.x+dx[i];
			nex.y=cur.y+dy[i];
			nex.z=cur.z+dz[i];
			//printf("%d %d %d\n",nex.x,nex.y,nex.z);
			
			if(cube[nex.x][nex.y][nex.z]==0&&!vis[nex.x][nex.y][nex.z]&&nex.x>=0&&nex.x<=a-1&&nex.y>=0&&nex.y<=b-1&&nex.z>=0&&nex.z<=c-1)
			{	//printf("%d %d %d\n",nex.x,nex.y,nex.z);
				vis[nex.x][nex.y][nex.z]=1;
				nex.step=cur.step+1;
				que.push(nex);
			}
		}
		
	}
return 0;
}
int main()
{	
	int t,time,ans;
	cin>>t;
	while(t--)
	{	vis[0][0][0]=1;
		cin>>a>>b>>c>>time;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				for(int k=0;k<c;k++)
				{	vis[i][j][k]=0;
					scanf("%d",&cube[i][j][k]);
				}
			}
		}
	ans=bfs();
	//cout<<ans<<endl; 
	if(ans<=time&&ans!=0) cout<<ans<<endl;
	else puts("-1");	
	}
}
