#include<bits/stdc++.h>
using namespace std;
int vis[105][105][105],r[5];
struct pos
{
	int num[5];
	int step;
}start,cur,nex;
int pour(int a,int b)
{
	int sum=cur.num[a]+cur.num[b];
	if(cur.num[a]==0||cur.num[b]==r[b]) return 0;//²»ÄÜµ¹ 
	if(r[b]>=sum)
	{
		nex.num[b]=sum;
	}
	else 
	{
		nex.num[b]=r[b];
	}
	nex.num[a]=sum-nex.num[b];
	return 1;
}
void bfs()
{
	queue<pos>que;
	que.push(start);
	while(!que.empty())	
	{	cur=que.front();
		que.pop();
		if(cur.num[0]==0&&cur.num[1]==cur.num[2]||cur.num[1]==0&&cur.num[0]==cur.num[2]||cur.num[2]==0&&cur.num[0]==cur.num[1])
		{
			cout<<cur.step<<endl;
			return;
		}
		//cout<<cur.step<<endl;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{	nex=cur;
				if(i!=j)
				{
					int t=pour(i,j);
					if(t&&!vis[nex.num[0]][nex.num[1]][nex.num[2]])
					{
						nex.step=cur.step+1;
					vis[nex.num[0]][nex.num[1]][nex.num[2]]=1;
					que.push(nex);
					}
				}
					//printf("%d %d %d\n",nex.num[0],nex.num[1],nex.num[2]);
					
				
				
			}
		}
		
	}
	cout<<"NO"<<endl;
} 
 int main()
 {
 	while(~scanf("%d%d%d",&r[0],&r[1],&r[2])&&(r[0]!=0||r[1]!=0||r[2]!=0))
 	{
 		start.num[0]=r[0];
 		start.num[1]=start.num[2]=0;
 		memset(vis,0,sizeof(vis));
 		memset(cur.num,0,sizeof(cur.num));
 		memset(nex.num,0,sizeof(nex.num));
 		cur.step=nex.step=0;
 		vis[start.num[0]][start.num[1]][start.num[2]]=1;
 		if(r[0]%2!=0) cout<<"NO"<<endl;
 		else bfs();
	 }
 }
