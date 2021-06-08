#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int t;
int cube[65][1300][130],vis[65][1300][130];
int dx[]={1,-1,0,0,0,0},dy[]={0,0,1,-1,0,0},dz[]={0,0,0,0,1,-1};
struct pos
{
	int x,y,z;
	int step;
}cur,nex;
int  bfs(int x,int y,int z)
{	int ans=0;
	cur.step=0;
	cur.x=x,cur.y=y,cur.z=z;
	vis[x][y][z]=1;
	queue<pos>que;
	que.push(cur);
	while(!que.empty())
	{
		cur=que.front();
		que.pop();
		ans++;
		//printf("a%db%dc%d",a,b,c);
		for(int i=0;i<6;i++)
		{
			nex.x=cur.x+dx[i];
			nex.y=cur.y+dy[i];
			nex.z=cur.z+dz[i];
			//printf("%d %d %d\n",nex.x,nex.y,nex.z);
			
			if(cube[nex.x][nex.y][nex.z]==1&&!vis[nex.x][nex.y][nex.z]&&nex.x>=0&&nex.x<=a-1&&nex.y>=0&&nex.y<=b-1&&nex.z>=0&&nex.z<=c-1)
			{	//printf("%d %d %d\n",nex.x,nex.y,nex.z);
				vis[nex.x][nex.y][nex.z]=1;
				nex.step=cur.step+1;
				que.push(nex);
			}
		}
		
	}
	if(ans<t) return 0;
	else return ans;

}
int main()
{	
	
		vis[0][0][0]=1;
		cin>>a>>b>>c>>t;
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<a;j++)
			{
				for(int k=0;k<b;k++)
				{	vis[j][k][i]=0;
					scanf("%d",&cube[j][k][i]);
				}
			}
		}
		int sum=0;
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<a;j++)
			{
				for(int k=0;k<b;k++)
				{	if (cube[j][k][i]==1&&vis[j][k][i]==0)
					sum+=bfs(j,k,i);
				}
			}
		}
		cout<<sum<<endl;
	
}
