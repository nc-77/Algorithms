#include<bits/stdc++.h>
using namespace std;
int e1,e2,b1,b2;
char s1[3],s2[3];
int dx[]={-1,-1,-2,-2,1,1,2,2},dy[]={-2,2,-1,1,2,-2,1,-1};
struct pos
{
	int x,y;
	int step;
}cur,nex;
bool pd()
{
	if(nex.x<=8&&nex.x>=1&&nex.y>=1&&nex.y<=8)
	return true;
return false;
}
void bfs()
{
	
	cur.step=0;
	queue<pos>que;
	que.push(cur);
	while(!que.empty())
	{	//printf("here\n");
		cur=que.front();
		que.pop();
		if(cur.x==e1&&cur.y==e2)
		{
			printf("To get from %c%c to %c%c takes %d knight moves.\n",s1[0],s1[1],s2[0],s2[1],cur.step);
			
			return;
		}
		for(int i=0;i<8;i++)
		{
			
				nex.x=cur.x+dx[i];
				nex.y=cur.y+dy[i];
				//printf("%d %d\n",nex.x,nex.y);
				if(pd())
				{	//printf("yes\n");
				nex.step=cur.step+1;
					que.push(nex);
				}
			
		}
		
	}
}
int main()
{	
    while(cin>>s1>>s2)
	{
		b1=(int)s1[0]-'a'+1;
		b2=s1[1]-'0';
		e1=(int)s2[0]-'a'+1;
		e2=s2[1]-'0';
		cur.x=b1;
		cur.y=b2;
		bfs();
	}
return 0;
}
